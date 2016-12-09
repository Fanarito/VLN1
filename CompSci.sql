DROP TABLE IF EXISTS "Computer_Types";
CREATE TABLE "Computer_Types"
(
"ID" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
"Computer_Type" VARCHAR UNIQUE
);
INSERT INTO "Computer_Types" VALUES(1,'Mechanical');
INSERT INTO "Computer_Types" VALUES(2,'Electronic');
INSERT INTO "Computer_Types" VALUES(3,'Electromechanical');
INSERT INTO "Computer_Types" VALUES(4,'Digital');
DROP TABLE IF EXISTS "Computers";
CREATE TABLE "Computers" 
(
"ID" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL ,
"Name" VARCHAR,
"Build_Year" INTEGER, 
"Computer_TypeID" INTEGER, 
"Built" BOOL,
"NationalityID" INTEGER, "Info" VARCHAR,
CONSTRAINT FK_Comp_Nationality FOREIGN KEY (NationalityID)
REFERENCES Nationality(ID),
CONSTRAINT FK_Comp_Type FOREIGN KEY (Computer_TypeID)
REFERENCES Computer_Type(ID)
);
INSERT INTO "Computers" VALUES(1,'Analytical Engine','',1,'FALSE',1,'Proposed in 1837. Successor to Babbage''s difference engine.');
INSERT INTO "Computers" VALUES(2,'Turing machine','',1,'FALSE',1,'Invented in 1936. A mathmatical model for a device that manipulates symbols on a strip of tape according to a table of rules.');
INSERT INTO "Computers" VALUES(3,'EDSAC',1947,2,'TRUE',2,'EDSAC 1 was shut down 11 July 1958.');
INSERT INTO "Computers" VALUES(4,'Harvard Mark I',1944,3,'TRUE',2,'Used in the war effort during the last part of World War II.');
INSERT INTO "Computers" VALUES(5,'Apollo Guidance Computer',1966,4,'TRUE',2,'Produced for the Apollo space program.');
INSERT INTO "Computers" VALUES(6,'Difference Engine No. 2',1991,1,'TRUE',1,'Designed between 1847 and1849. Tabulates polynomial functions.');
INSERT INTO "Computers" VALUES(8,'Colossus',1943,2,'TRUE',1,'Used for cryptanalysis and regarded as the world''s first programmable, electronic, digital computer.');
INSERT INTO "Computers" VALUES(9,'Atanasoff Berry Computer',1942,2,'TRUE',2,'The first automatic electronic digital computer, designed to solve systems of linear equations.');
INSERT INTO "Computers" VALUES(10,'ENIAC',1946,2,'TRUE',2,'Turing-complete, digital and reprogrammable. ');
INSERT INTO "Computers" VALUES(11,'Z3',1941,3,'TRUE',5,'The world''s first working programmable, fully automatic digital computer.');
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
INSERT INTO "Connections" VALUES(2,1,2);
INSERT INTO "Connections" VALUES(3,1,3);
INSERT INTO "Connections" VALUES(4,2,4);
INSERT INTO "Connections" VALUES(5,3,11);
INSERT INTO "Connections" VALUES(6,4,5);
INSERT INTO "Connections" VALUES(7,5,6);
INSERT INTO "Connections" VALUES(8,6,3);
INSERT INTO "Connections" VALUES(9,8,1);
INSERT INTO "Connections" VALUES(10,9,12);
INSERT INTO "Connections" VALUES(11,11,13);
DROP TABLE IF EXISTS "Nationality";
CREATE TABLE "Nationality" ("ID" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "Nationality" VARCHAR UNIQUE);
INSERT INTO "Nationality" VALUES(1,'English');
INSERT INTO "Nationality" VALUES(2,'American');
INSERT INTO "Nationality" VALUES(3,'Canadian');
INSERT INTO "Nationality" VALUES(4,'Dutch');
INSERT INTO "Nationality" VALUES(5,'German');
DROP TABLE IF EXISTS "Persons";
CREATE TABLE "Persons" ("ID" INTEGER PRIMARY KEY  NOT NULL ,"Name" VARCHAR NOT NULL ,"Sex" VARCHAR NOT NULL ,"Birth_Year" INTEGER NOT NULL ,"Death_Year" INTEGER,"NationalityID" INTEGER NOT NULL ,"Info" VARCHAR NOT NULL  DEFAULT (null) );
INSERT INTO "Persons" VALUES(1,'Tommy Flowers','m',1905,1998,1,'English engineer who designed the Colossus computer for cryptanalysis during WWII.');
INSERT INTO "Persons" VALUES(2,'Ada Lovelace','f',1815,1852,1,'Mathematician and writer, chiefly known for her work on Charles Babbages early mechanical general-purpose computer, the Analytical Engine.');
INSERT INTO "Persons" VALUES(3,'Charles Babbage','m',1791,1871,1,'Mathematician, philosopher, inventor and mechanical engineer. Is best remembered for originating the concept of a programmable computer.');
INSERT INTO "Persons" VALUES(4,'Alan Turing','m',1912,1954,1,'Computer scientist, mathematician, logician, cryptanalyst and theoretical biologist. Highly influential in the development of theoretical computer science, providing a formalisation of the concepts of algorithm and computation with the Turing machine.');
INSERT INTO "Persons" VALUES(5,'Grace Hopper','f',1906,1992,2,'Computer scientist and United States Navy Rear Admiral. Invented the first compiler for a computer programming language, COBOL.');
INSERT INTO "Persons" VALUES(6,'Margaret Hamilton','f',1936,'',2,'Computer scientist, systems engineer, and business owner. Director of the Software Engineering Division of the MIT Instrumentation Laboratory, which developed on-board flight software for the Apollo space program.');
INSERT INTO "Persons" VALUES(7,'Edsger W. Dijkstra','m',1930,2002,4,'Computer scientist and mathematician. One of the most influential members of computing sciences founding generation, Dijkstra helped shape the new discipline from both an engineering and a theoretical perspective.');
INSERT INTO "Persons" VALUES(8,'Donald Knuth','m',1938,'
',2,'Computer scientist, mathematician, and professor emeritus at Stanford University. Author of The Art of Computer Programming. Contributed to the development of the rigorous analysis of the computational complexity of algorithms.');
INSERT INTO "Persons" VALUES(9,'Douglas Engelbart','m',1925,2013,2,'Engineer, inventor, computer- and Internet pioneer. He is best known for his work on founding the field of human–computer interaction, particularly his contribution to the creation of the computer mouse.');
INSERT INTO "Persons" VALUES(10,'Kenneth E. Iverson','m',1920,2004,3,'Computer scientist. Noted for the development of the APL programming language.');
INSERT INTO "Persons" VALUES(11,'Maurice Wilkes','m',1913,2010,1,'Computer scientist. Led a team which developed a computer, known as EDSAC.');
INSERT INTO "Persons" VALUES(12,'John Vincent Atanasoff','m',1903,1995,2,'American physicist who invented the first electronic digital computer.');
INSERT INTO "Persons" VALUES(13,'Konrad Zuse','m',1910,1995,5,'German civil engineer and pioneer often regarded as the inventor of the modern computer.');
INSERT INTO "Persons" VALUES(14,'Testy','m',1930,0,7,'A aussie walks into a bar');
