MyDict = {'Alex':'Asdf1234',
          'Roy': 'Qwer1234',
          'Bob':'Zxcv1234'}


print("Login")
usrname = str(input("Input username: "))
while usrname not in MyDict:
    print("Username doesn't exist")
    usrname = str(input("Try input username again: "))
    passw = str(input('Input password: '))
while passw.values() not in MyDict.values():
    print('Wrong password')
    passw = str(input('Try input password again: '))
else:
        print("Welcome!")

if option != 1 and option != 2:
    print("Option doesn't exist")
