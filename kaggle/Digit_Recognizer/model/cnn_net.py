import csv
import numpy as np
import pandas as pd
import tensorflow as tf
from sklearn.model_selection import train_test_split
from tensorflow.keras import datasets, layers, optimizers, Sequential, metrics

train_set = pd.read_csv('../data/train.csv')
test_set = pd.read_csv('../data/test.csv')

xs = (train_set.iloc[: , 1:].values).astype('float32')
ys = (train_set.iloc[: , [0]].values).astype('int32')
x_test = test_set.values.astype('float32')

x_train , x_valid , y_train , y_valid = train_test_split(xs , ys , test_size = 0.2)

x_train = tf.convert_to_tensor(x_train, dtype=tf.float32) / 255.0
x_valid = tf.convert_to_tensor(x_valid, dtype=tf.float32) / 255.0
x_train = tf.reshape(x_train, (-1,28,28))
x_valid = tf.reshape(x_valid, (-1,28,28))


db = tf.data.Dataset.from_tensor_slices((x_train, y_train))
db = db.batch(32).repeat(10)

network = tf.keras.Sequential([
    layers.Conv2D(64 , (3,3) ,activation='relu', input_shape=(28, 28, 1)), 
    layers.MaxPooling2D(2,2),
    layers.Conv2D(128 , (3,3) ,activation='relu'), 
    layers.MaxPooling2D(2,2),
    layers.Flatten(),
    layers.Dense(512, activation='relu'),
    layers.Dropout(0.2),
    layers.Dense(128, activation='relu'),
    layers.Dropout(0.2),
    layers.Dense(10 , activation = 'softmax')                   
])
network.build(input_shape=(None, 28*28))
network.summary()

optimizer = optimizers.SGD(lr=0.01)
acc_meter = metrics.Accuracy()

for step, (x,y) in enumerate(db):

    with tf.GradientTape() as tape:
        # [b, 28, 28] => [b, 10]
        out = network(x)
        # [b] => [b, 10]
        y = tf.reshape(y,-1)
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

        out_valid = network(x_valid)
        y_valid = tf.reshape(y_valid,-1)
        acc_meter.update_state(tf.argmax(out_valid, axis=1), y_valid)
        print(step, 'valid acc:', acc_meter.result().numpy())
        acc_meter.reset_states()

x_test = tf.convert_to_tensor(x_test, dtype=tf.float32) / 255.0
x_test = tf.reshape(x_test, (-1,28,28))
out = network(x_test)
result = tf.argmax(out, axis=1).numpy()
print(result.shape)
with open('../save/submission.csv','w') as f:
    f.write('ImageId,Label\n')
    for i in range(0,result.shape[0]):
        f.write(str(i+1)+','+str(result[i])+'\n')

