import re
def order(sentence):
  # code here
  result1 = sentence.split(' ')
  result2 = []
  for i in xrange(0,10):
    for item in result1:
      print i, item
      if (re.search(str(i),item)):
        result2.append(item)
  ' '.join(result2)
  return result2

order("This1 is2 test4 a3")

