# picElectronicLock
Project Description:
The objective of this project is to design and develop an electronic lock using a Pic microcontroller. The system comprises a user-friendly keypad that prompts the user to input a unique security PIN. Based on the input received, the program will be designed to execute a desired action, such as opening a door or activating an LED. Through the integration of the Pic microcontroller, this electronic lock promises to offer enhanced security and convenience to its users.

Circuit Components required:
•	PIC16F877A Controller
•	Liquid Crystal Display
•	7 Segment Display
•	Keypad
•	Buzzer

How the System Works:
The project has 4 functionalities:
1.	Register
2.	Login
3.	Delete user
4.	Display How many people entered

For the user to register, the user has to enter a unique 2 digit ID. Then for the corresponding user a 3 digit password space is created. So the user will be prompted to enter a 3 digit password. After doing this process, the password will be displayed on the 7 segment display for the user to note the password once more.
When the user wants to enter, the same ID and Password should be used. If the ID and Password matches, the LCD will show that the user is authentic and he will be prompted to enter. To correspondingly apply input to one of the output such as attaching a motor or led, the 7 segment display will also show 333 if the user has entered the password correctly. If the user is not an authentic user, the LCD will show that the password is wrong, and for security of the system, the buzzer will get activated.
If a user wants to discontinue from the system, he will be prompted to enter the ID. Then the specific password spaces will be filled by zeroes, and so the user with the ID will not be able to login before registering.
Whenever a user correctly enters the passwords and enters into the system, a global variable count will get incremented by one. Therefore, at the end of the day if someone wants to checks how many users have entered into the system, the number will be displayed on the 7 segment display.

Applications:
1.	Door locking system
2.	Safety Lockers
3.	Attendance Monitoring in Labs
4.	Employee Management for resource access
5.	Mail Login
6.	UI/UX in Web and Android DBMS
7.	Firebase extensions – Server Access



