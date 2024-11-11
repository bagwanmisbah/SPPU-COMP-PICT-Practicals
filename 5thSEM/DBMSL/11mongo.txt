use temp

db.createCollection("classes");

db.classes.insert(
    {
        class:"Database Management System",
        start:new Date(2024,7,1),
        students:[
            {fname:"Misbah",lname:"Bagwan"},
            {fname:"Aryan",lname:"Kadole"},
            {fname:"Mansi",lname:"Jangle"},      
        ],
        cost:2400,
        professor:"Pranjal Joshi",
        topics:"RDBMS,DDL,DCL,TCL,ER Diagram",
        book:
            {
                isbn:4567891823,
                title:"Guide to DBMS",
                price:675.45
            }
    })

db.classes.insert(
{
class:"Theory of Computation",
start:new Date(2024,7,3),
students:[
{fname:"Farkh",lname:"Dalal"},
{fname:"Nilakshi",lname:"Sonawane"},
{fname:"Aryan",lname:"Kadole"},
],
cost:5900,
professor:"Girish Potdar",
topics:"DFA,NFA,MDFA,Mealy,Moore,RegEx",
book:
{
isbn:45701254721,
title:"The Turing Machine",
price:981.33
}
})



db.classes.insert({
class:"System Programming and Operating Systems",
start:new Date(2024,7,4),
students:[
{fname:"Misbah",lname:"Bagwan"},
{fname:"Aryan",lname:"Kadole"},
{fname:"Mansi",lname:"Jangle"},
],
cost:4500,
professor:"Rekha A.Kulkarni",
topics:"Assembler,Macro,Compiler,interpreter,Scheduling",
book:
{
isbn:984165723,
title:"SPOS for Beginners",
cost:550.25
}
})






db.classes.insert({
class:"Computer Networks and Security",
start:new Date(2024,7,7),
students:[
{fname:"Misbah",lname:"Bagwan"},
{fname:"Nilakshi",lname:"Sonawane"},
{fname:"Farkh",lname:"Dalal"},
],
cost:1000,
professor:"Preeti A.Jain",
topics:"Topologies,OSI Model,Hamming and CRC,use of Wireshark and packet tracer",
book:
{
isbn:019834571,
title:"DC and N by Bahrouz Farouzan's ",
cost:1500.75
}
})

db.classes.insert({
class:"Human Computer Interface",
start:new Date(2024,7,2),
students:
[
{fname:"Misbah",lname:"Bagwan"},
{fname:"Mansi",lname:"Jangle"},
],
cost:1200,
professor:"Urmila Pawar",
topics:"Schneider principles,Norman's rules,Goals of Evalution",
book:
{
isbn:22312572,
title:"Simplifying Interfaces",
cost:240.69
}
})

db.classes.insert({
class:"Cyber Security Honors",
start:new Date(2024,7,9),
students:[
{fname:"Misbah",lname:"Bagwan"},
{fname:"Nilakshi",lname:"Sonawane"},
{fname:"Farkh",lname:"Dalal"},
],
cost:3400,
professor:"Preeti A.Jain",
topics:"Principles of cyber security ,Asymmetric key, encryption ,decryption",
book:
{
isbn:019834571,
title:"CB by TanenBaum ",
cost:1450.75
}
})

// 1. How many classes does “Preeti A.Jain” teach

var map1 = function () { emit(this.professor, 1); }
var reduce1 = function (Prof, Count) { return Array.sum(Count); }

db.classes.mapReduce(map1, reduce1, 
{ query: { professor: "Preeti A.Jain" }, out: 'result1' });
db.result1.find();

// 2. Find the total no. of students enrolled for each class
var map2 = function () { emit(this.class, this.students.length); }
var reduce2 = function (Class, Count) { return Array.sum(Count); }

db.classes.mapReduce(map2, reduce2, { out: 'result2' });
db.result2.find();


var map3=function(){emit(this.class,this.cost);};
var reduce3=function(key,values){ return values;};

db.classes.mapReduce(map3,reduce3,{out:'result3'});
db.result3.find().sort({value:1});

// 3. Find the total no. of classes conducted by each professor and also the total cost to attend each of the professor’s classes
var map3 = function () { emit(this.professor, { cost: this.cost, count: 1 }); }
var reduce3 = function (prof, values) {
    var value = { cost: 0, count: 0 };
    for (let i = 0; i < values.length; i++) {
        value.count += values[i].count;
        value.cost += values[i].cost;
    }
    return value;
}

db.classes.mapReduce(map3, reduce3, { out: 'result4' });
db.result4.find();


db.result.find();



Output:
switched to db temp
{ "ok" : 1 }
WriteResult({ "nInserted" : 1 })
WriteResult({ "nInserted" : 1 })
WriteResult({ "nInserted" : 1 })
WriteResult({ "nInserted" : 1 })
WriteResult({ "nInserted" : 1 })
WriteResult({ "nInserted" : 1 })
{ "result" : "result1", "ok" : 1 }
{ "_id" : "Preeti A.Jain", "value" : 8 }
{ "result" : "result2", "ok" : 1 }
{ "_id" : "Theory of Computation", "value" : 12 }
{ "_id" : "Database Management System", "value" : 12 }
{ "_id" : "Human Computer Interface", "value" : 8 }
{ "_id" : "Cyber Security Honors", "value" : 12 }
{ "_id" : "Computer Networks and Security", "value" : 12 }
{ "_id" : "System Programming and Operating Systems", "value" : 12 }
{ "result" : "result3", "ok" : 1 }
{ "_id" : "Computer Networks and Security", "value" : [ 1000, 1000, 1000, 1000 ] }
{ "_id" : "Human Computer Interface", "value" : [ 1200, 1200, 1200, 1200 ] }
{ "_id" : "Database Management System", "value" : [ 2400, 2400, 2400, 2400 ] }
{ "_id" : "Cyber Security Honors", "value" : [ 3400, 3400, 3400, 3400 ] }
{ "_id" : "System Programming and Operating Systems", "value" : [ 4500, 4500, 4500, 4500 ] }
{ "_id" : "Theory of Computation", "value" : [ 5900, 5900, 5900, 5900 ] }
{ "result" : "result4", "ok" : 1 }
{ "_id" : "Girish Potdar", "value" : { "cost" : 23600, "count" : 4 } }
{ "_id" : "Rekha A.Kulkarni", "value" : { "cost" : 18000, "count" : 4 } }
{ "_id" : "Urmila Pawar", "value" : { "cost" : 4800, "count" : 4 } }
{ "_id" : "Preeti A.Jain", "value" : { "cost" : 17600, "count" : 8 } }
{ "_id" : "Pranjal Joshi", "value" : { "cost" : 9600, "count" : 4 } }










