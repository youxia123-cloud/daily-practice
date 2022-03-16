from __future__ import absolute_import,division,print_function
import ssl
import tensorflow as tf
import tensorflow.keras as keras
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from tensorflow import feature_column
ssl.create_default_https_context = ssl._create_unverified_context
# 使用pandas读取数据
URL = 'heart.csv'
dataframe = pd.read_csv(URL)
# 划分训练集和测试集
train, test = train_test_split(dataframe,test_size=0.2)
train,val = train_test_split(train,test_size=0.2)
# 定义时数据集随机分布的函数
def df_to_dataset(dataframe,shuffle=True,batch_size=32):
    dataframe = dataframe.copy()
    labels = dataframe.pop('target')
    ds = tf.data.Dataset.from_tensor_slices((dict(dataframe),labels))
    if shuffle:
        ds = ds.shuffle(buffer_size=len(dataframe))
    ds = ds.batch(batch_size)
    return ds
# 定义batch_size常量
batch_size = 5
# 使用定义的函数对数据进行处理
train_ds = df_to_dataset(train,batch_size=batch_size)
val_ds = df_to_dataset(val,shuffle=False,batch_size=batch_size)
test_ds = df_to_dataset(test,shuffle=False,batch_size=batch_size)
example_batch = next(iter(train_ds))[0]
# 定义数据输出函数
def print_data(feature_column):
    feature_layer = keras.layers.DenseFeatures(feature_column)
    print(feature_layer(example_batch).numpy())
# 构建数字列
age = feature_column.numeric_column("age")
print_data(age)
print_data(age)



