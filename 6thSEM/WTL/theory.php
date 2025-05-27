<?php
$colors=array("red","blue","green");
//INDEXED ARRAY
foreach($colors as $value)
{
    echo " \ncolor: ".$value;
}
echo "\n_____";
unset($colors[1]);
foreach($colors as $value)
{
    echo " \ncolor: ".$value;
}
echo "\n_____";
//MIXED ARRAY 
$nums=array("one",2,3,"four");
foreach($nums as $value)
{
    echo " \nnum: ".$value;
}
echo "\n_____";
//ASSOCIATIVE ARRAY 
$stud_id=array("ABC"=>1,"DEF"=>2,"PQR"=>3);
echo " \nPQR student id: ".$stud_id["PQR"];

//MULTI DIMENSIONAL ARRAY 
$emp =array(
    array("alice",24,"engineer"),
    array("bob",20,"clerk"),
    array("Charlie",35,"manager")
    );
echo "\nCharlie 's age :";
echo $emp[2][1];

echo "\n",count($emp);
print_r($colors);
print_r($nums);
?>
--------------------------------------------
<?php
$age=17;
if($age>=18)
{
    echo "you are eligible to vote";
}
else
{
    echo "you are not eligible to vote";
}

echo "\n";
$marks=75;
if($marks>=90)
{
    echo "grade a";
}
elseif($marks>=75)
{
    echo "grade b";
}
else
{
    echo "grade c";
}

$num=2;
switch($num)
{
    case 1:
        echo "\none";
        break;
    case 2:
        echo "\ntwo";
        break;
    default:
        echo "another day";
    
}

?>
--------------------------------------------
<?php

$i=1;

while($i<=5)
{
    echo "\n$i";
    $i++;
}

$i = 1;

for($i = 1; $i <= 5; $i++){
    if($i == 3){
        continue;
    }
    echo "$i ";
}

?>
--------------------------------------------
<?php
//simple user defined 
function add($a,$b)
{
    return $a+$b;
}
echo add(5,8);
//default parameters

function greet($name = "guest")
{
    echo "\nsession reloaded ,welcome back $name ";
}

greet();
greet("mishu");

function increment(&$x)
{
    $x++;
}
$a=5;
increment($a);
echo "\nincremented value " .$a;

function sum(...$nums)
{
    return array_sum($nums);
}
echo "\n";
echo sum(10,10,10);

//arrow function
$sq=fn($a)=>$a*$a;
echo "\n";
echo $sq(5);

?>


