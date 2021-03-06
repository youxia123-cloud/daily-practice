# 该文件可以在Jupyter Notebook中运行
# !pip install polyglot
# !pip install pyicu
# !pip install pycld2
# !pip install morfessor
!polyglot download morph2.en
import polyglot
from nltk.stem import PorterStemmer
from polyglot.text import Text,Word

word = "unexpected"
text = "disagreement"
text1 = "diasgree"
text2 = "agreement"
text3 = "quikeiness"
text4 = "historical"
text5 = "canonical"
text6 = "happiness"
text7 = "unkind"
text8 = "dogs"
text9 = "expected"
words_derv = ["happiness","unkind"]
word_infle = ["dogs","expected"]
words = ["unexpected","disagreement","disagree","agreement","quikiness","canonical","historical"]

def stemmer_porter():
    port = PorterStemmer()
    print("\nDerivational Morphemes")
    print("".join([port.stem(i) for i in text6.split()]))
    print("".join([port.stem(i) for i in text7.split()]))
    print("\nInflectional Morphemes")
    print("".join([port.stem(i) for i in text8.split()]))
    print("".join([port.stem(i) for i in text9.split()]))
    print("\nSome examples")
    print("".join([port.stem(i) for i in word.split()]))
    print("".join([port.stem(i) for i in text.split()]))
    print("".join([port.stem(i) for i in text1.split()]))
    print("".join([port.stem(i) for i in text2.split()]))
    print("".join([port.stem(i) for i in text3.split()]))
    print("".join([port.stem(i) for i in text4.split()]))
    print("".join([port.stem(i) for i in text5.split()]))



def polygolt_stem():
    print("\nDerivational Morphemes using polyglot library")
    for w in words_derv:
        w = Word(w,language="en")
        print("{:<20}{}".format(w,w.morphemes))
    print("\nInflectional Morphemes using polyglot library")
    for w in word_infle:
        w = Word(w,language="en")
        print("{:<20}{}".format(w,w.morphemes))
    print("\nSome examples using polyglot library")
    for w in word_infle:
        w = Word(w,language="en")
        print("{:<20}{}".format(w,w.morphemes))


stemmer_porter()
polygolt_stem()