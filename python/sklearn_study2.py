# -*- coding: utf-8 -*-
"""sklearn_study2.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/10sA4Ijs4oarG2-a0BCrCy-BURjblvsXx
"""

# KNN模型
# KNN模型是一种用于回归任务和分类任务的简单模型
import numpy as np
import matplotlib.pyplot as plt
from collections import Counter
from sklearn.preprocessing import LabelBinarizer
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
from sklearn.metrics import recall_score
from sklearn.metrics import f1_score
from sklearn.metrics import matthews_corrcoef
from sklearn.metrics import classification_report

X_train = np.array([
    [158,64],
    [170,86],
    [183,84],
    [191,80],
    [155,49],
    [163,59],
    [180,67],
    [178,54],
    [170,67]
])
y_train = ['male','male','male','male','female','female','female','female','female']
plt.figure()
plt.title('Human Heights and Weights by Sex')
plt.xlabel('Height in cm')
plt.ylabel('weight in kg')
for i,x in enumerate(X_train):
  # 使用‘x'标记表示训练实例中的男性，使用菱形标记表示训练实例中的女性
  plt.scatter(x[0],x[1],c='k',marker='x' if y_train[i]=='male' else 'D' )
plt.grid(True)
plt.show()
# 计算出测试实例和所有训练实例之间的距离，并找出距离最近的邻居中最普遍的性别
x = np.array([[155,70]])
distances = np.sqrt(np.sum((X_train-x)**2,axis=1))
print(distances)
nearest_neighbor_indices = distances.argsort()[:3]
nearest_neighbor_genders = np.take(y_train,nearest_neighbor_indices)
print(nearest_neighbor_genders)
b = Counter(np.take(y_train,distances.argsort()[:3]))
b.most_common(1)[0][0]
# 使用sklearn类库实现一个KNN分类器
lb = LabelBinarizer()
y_train_binarized = lb.fit_transform(y_train)
print(y_train_binarized)
K = 3
clf = KNeighborsClassifier(n_neighbors=K)
clf.fit(X_train,y_train_binarized.reshape(-1))
prediction_binarized = clf.predict(np.array([155,70]).reshape(1,-1))[0]
predict_label = lb.inverse_transform(prediction_binarized)
print(predict_label)
X_test = np.array([
        [168,65],
        [180,96],
        [160,52],
        [169,67]
])
y_test = ['male','male','female','female']
y_test_binarized = lb.transform(y_test)
print('Binarized labels:%s'%y_test_binarized.T[0])
predictions_binarized = clf.predict(X_test)
print('Binarized predictions:%s'%predictions_binarized)
print('Predicted labels:%s'%lb.inverse_transform(predictions_binarized))
# 打印准确率
print('Accuracy:%s'%accuracy_score(y_test_binarized,predictions_binarized))
# 打印召回率
print('Recall:%s'%recall_score(y_test_binarized,predictions_binarized))
# 打印F1度量
print('F1 score:%s'%f1_score(y_test_binarized,predictions_binarized))
# 打印马修斯相关系数
print('Matthews correlation coefficient:%s'%matthews_corrcoef(y_test_binarized,predictions_binarized))
# 对模型的评估
print("----------------")
print(classification_report(y_test_binarized,predictions_binarized,target_names=['male'],labels=[1]))