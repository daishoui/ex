import csv
import numpy as np
import tensorflow as tf
from tensorflow.keras import datasets, layers, optimizers, Sequential, metrics

def load_train_data(csv_file):
    with open(csv_file) as f:
        reader = csv.reader(f)
        lines = list(reader)
    X = np.array([[lines[i][j] for j in range(1,len(lines[i]))] for i in range(1,len(lines))])
    y = np.array([int(lines[i][0]) for i in range(1,len(lines))])
    return X,y

xs, ys = load_train_data("../data/train.csv")


def load_test_data(csv_file):
    with open(csv_file) as f:
        reader = csv.reader(f)
        lines = list(reader)
    X = np.array([[lines[i][j] for j in range(0,len(lines[i]))] for i in range(1,len(lines))])
    return X


xs = tf.convert_to_tensor(xs, dtype=tf.float32) / 255.0

db = tf.data.Dataset.from_tensor_slices((xs,ys))
db = db.batch(32).repeat(10)


network = Sequential([layers.Dense(256, activation='relu'),
                     layers.Dense(256, activation='relu'),
                     layers.Dense(256, activation='relu'),
                     layers.Dense(10)])
network.build(input_shape=(None, 28*28))
network.summary()

optimizer = optimizers.SGD(lr=0.01)
acc_meter = metrics.Accuracy()

for step, (x,y) in enumerate(db):

    with tf.GradientTape() as tape:
        # [b, 28, 28] => [b, 784]
        x = tf.reshape(x, (-1, 28*28))
        # [b, 784] => [b, 10]
        out = network(x)
        # [b] => [b, 10]
        y_onehot = tf.one_hot(y, depth=10)
        # [b, 10]
        loss = tf.square(out-y_onehot)
        # [b]
        loss = tf.reduce_sum(loss) / 32


    acc_meter.update_state(tf.argmax(out, axis=1), y)

    grads = tape.gradient(loss, network.trainable_variables)
    optimizer.apply_gradients(zip(grads, network.trainable_variables))


    if step % 200==0:

        print(step, 'loss:', float(loss), 'acc:', acc_meter.result().numpy())
        acc_meter.reset_states()


test_xs = load_test_data("../data/test.csv")
test_xs = tf.convert_to_tensor(test_xs, dtype=tf.float32) / 255.0
test_xs = tf.reshape(test_xs, (-1, 28*28))
out = network(test_xs)
result = tf.argmax(out, axis=1).numpy()
print(result.shape)
with open('../save/submission.csv','w') as f:
    f.write('ImageId,Label\n')
    for i in range(0,result.shape[0]):
        f.write(str(i+1)+','+str(result[i])+'\n')

