# VLN1
-------------------
GENERAL USAGE NOTES
-------------------
It is important to move the database CompSci.sqlite into your build file. Otherwise you will not be able to acces the database. 

------------------------------------------------------------
The program can do the following operations on the database.
------------------------------------------------------------
* **list**
This command will list one of the five tables from the database of your choice. If you choose to list connections, the program will ask
for person or computer, depending on whether you want to display all computers connected  to persons or persons connected to computers.

* **add**
This will add a new famous programmer, computer, connection, nationality or computer type to the system. If you want to add a programmer
or a computer you will be asked to fill in all their properties with instructions. 

* **change** 
This will change a famous programmer or computer in the system. You will be asked to change one or more properties of the object with 
instructions. You can keep some of their properties unchanged or all if you cancel.

* **remove**
This will remove a famous programmer or computer from the system

* **sort**
This will sort the list of persons or computers according to your preferences. You can sort persons by id, name, birth year, death year
or nationality. For computers you can sort them by id, name, built year, computer type, built or nationality. For each case you can decide
if you want the list to be ascending or descending. 

* **search**
You can choose if you want to search for a person or a computer. This will search the system for a variable of your choice. The variable 
has to be one of their properties. 

* **info**
This will display information about a famous programmer or computer.

* **clear**
This will clear the screen.

* **quit**
This will quit the program.
