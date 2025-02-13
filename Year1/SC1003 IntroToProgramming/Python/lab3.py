def Register():        
    username = str(input("Input username: "))
    while username in MyDict:
        print('Username has been taken')
        username = str(input("Input username: "))
        
    pwd=str(input('Input password: '))
    count1 =1
    while count1!= 0:
        if (len(pwd)<9):
            print("Password too short")
            pwd=str(input("Input password again:"))
        if not re.search("[1-9]",pwd):
            print("Password has no numbers")
            pwd=str(input("Input password again:"))
        if not re.search("[a-z]", pwd):
            print("Password doesnt have lowercase letter")
            pwd=str(input("Input password again:"))
        if not re.search("[A-Z]", pwd):
            print("Password doesnt have uppcase letter")
            pwd=str(input("Input password again:"))
        else:
            print("Valid password. User registered")
            

            MyDict[username] = pwd
            print(MyDict)
            break

  

def Login():
    print("Login")
    usrname = str(input("Input username: "))
    while usrname not in MyDict:
        print("Username doesn't exist")
        usrname = str(input("Try input username again: "))
    passw = str(input('Input password: '))
    while passw not in MyDict.values():
        print('Wrong password')
        passw = str(input('Try input password again: '))
    else:
        print("Welcome!")


                
        
    















    
   
    
