DROP TABLE IF EXISTS "Computers";
CREATE TABLE "Computers" 
(
"ID" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , 
"Build_Year" INTEGER, 
"Computer_Type" VARCHAR, 
"Built" BOOL,
"NationalityID" INTEGER,
CONSTRAINT FK_Comp_Nationality FOREIGN KEY (NationalityID)
REFERENCES Nationality(ID)
);
INSERT INTO "Computers" VALUES(1,1970,'Abstract','TRUE',1);
DROP TABLE IF EXISTS "Connections";
CREATE TABLE "Connections" 
(
"ID" INTEGER PRIMARY KEY  NOT NULL ,
"ComputersID" INTEGER,
"PersonsID" INTEGER,
CONSTRAINT FK_Computers FOREIGN KEY (ComputersID)
REFERENCES Computers(ID),
CONSTRAINT FK_Persons FOREIGN KEY (PersonsID)
REFERENCES Persons(ID)
);
INSERT INTO "Connections" VALUES(1,1,1);
DROP TABLE IF EXISTS "Nationality";
CREATE TABLE "Nationality" ("ID" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "Nationality" VARCHAR);
INSERT INTO "Nationality" VALUES(1,'English');
INSERT INTO "Nationality" VALUES(2,'American');
INSERT INTO "Nationality" VALUES(3,'Canadian');
INSERT INTO "Nationality" VALUES(4,'Dutch');
DROP TABLE IF EXISTS "Persons";
CREATE TABLE "Persons" 
(
"ID" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , 
"Name" VARCHAR NOT NULL , 
"Sex" VARCHAR NOT NULL , 
"Birth_Year" INTEGER NOT NULL , 
"Death_Year" INTEGER, 
"NationalityID" INTEGER NOT NULL , 
"Description" VARCHAR NOT NULL ,
CONSTRAINT FK_Nationality FOREIGN KEY (NationalityID)
REFERENCES Nationality(ID)
);
INSERT INTO "Persons" VALUES(1,'Tester McTester','m',1950,1980,1,'Tester testes the test');
INSERT INTO "Persons" VALUES(2,'Ada Lovelace','f',1815,1852,1,'Mathematician and writer, chiefly known for her work on Charles Babbages early mechanical general-purpose computer, the Analytical Engine.');
INSERT INTO "Persons" VALUES(3,'Charles Babbage','m',1791,1871,1,'Mathematician, philosopher, inventor and mechanical engineer. Is best remembered for originating the concept of a programmable computer.');
INSERT INTO "Persons" VALUES(4,'Alan Turing','m',1912,1954,1,'Computer scientist, mathematician, logician, cryptanalyst and theoretical biologist. Highly influential in the development of theoretical computer science, providing a formalisation of the concepts of algorithm and computation with the Turing machine.');
INSERT INTO "Persons" VALUES(5,'Grace Hopper','f',1906,1992,2,'Computer scientist and United States Navy Rear Admiral. Invented the first compiler for a computer programming language, COBOL.');
INSERT INTO "Persons" VALUES(6,'Margaret Hamilton','f',1936,0,2,'Computer scientist, systems engineer, and business owner. Director of the Software Engineering Division of the MIT Instrumentation Laboratory, which developed on-board flight software for the Apollo space program.');
INSERT INTO "Persons" VALUES(7,'Edsger W. Dijkstra','m',1930,2002,4,'Computer scientist and mathematician. One of the most influential members of computing sciences founding generation, Dijkstra helped shape the new discipline from both an engineering and a theoretical perspective.');
INSERT INTO "Persons" VALUES(8,'Donald Knuth','m',1938,0,2,'Computer scientist, mathematician, and professor emeritus at Stanford University. Author of The Art of Computer Programming. Contributed to the development of the rigorous analysis of the computational complexity of algorithms.');
INSERT INTO "Persons" VALUES(9,'Douglas Engelbart','m',1925,2013,2,'Engineer, inventor, computer- and Internet pioneer. He is best known for his work on founding the field of human–computer interaction, particularly his contribution to the creation of the computer mouse.');
INSERT INTO "Persons" VALUES(10,'Kenneth E. Iverson','m',1920,2004,3,'Computer scientist. Noted for the development of the APL programming language.');
INSERT INTO "Persons" VALUES(11,'Maurice Wilkes','m',1913,2010,1,'Computer scientist. Led a team which developed a computer, known as EDSAC.');
