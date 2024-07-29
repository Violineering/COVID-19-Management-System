# COVID-19-Management-System
My first C++ Program
1.3 SYSTEM MODULES

1.3.1 MODULE 1: USER LOGIN
	User are requiring to login into the program first to access full functional program. In this function, user need to enter correct username and password. If user does not have an account, the username ‘admin’ and password ‘admin’ will be used to enter the program and create an account for user.

1.3.2 MODULE 2: USERS REGISTARTION
	In program, users are required to register their own account which stored all the information and access to Covid-19 health mentoring program. The user will provide their personal information and admin will manually key-in the information and helps user to create an account. For admin to register an account, he or she need to choose choice ‘4’ by entering ‘admin’ as username and ‘admin’ as password as well. The information required to register an account is username, password, age, contact number and user’s address. If the user’s age cannot be used, the statement ‘Invalid age…. Enter again:’ will be shown. In program, the user’s information is store in text file, which is ‘user.txt’

1.3.3 MODULE 3: USERS SHOW STATUS
	If the user wants to see his or her own risk status, user may choose choice ‘1’ which is ‘SHOW STATUS’. The program had made a unique function definition for choice ‘1’. Inside function definition, program will show user full name and category. If user’s category is ‘A’, the user has been confirmed case positive in Covid-19 and have high risky while user which is in category ‘B’ is user who have been suspected or close contact with individuals from category ‘A’. For user in category ‘C’, is the user who is tested negative in Covid-19 test and no risky. The suspected action or tips are given for all user either in category ‘A’,’B’ or ‘C’ in this function.

1.3.4 MODULE 4: USERS UPDATE STATUS
	If user want to update his or her Covid-19 status, user may choose choice ‘2’ which is ‘UPDATE STATUS’. Users may update their category such as ‘A’,’B’ or ‘C’ according to their own risk status. After update, user may check their Covid-19 risk status again by choosing choice ‘1’ which is ‘SHOW STATUS’.
