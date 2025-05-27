<?php
$cookie_period=time()+60*60*24;
setcookie("myname","haha",$cookie_period);

if(isset($_COOKIE["myname"]))
{
    echo "Welcome ".$_COOKIE["myname"];
}
else
{
    echo "Welcome Guest";
}
?>

---------------------------------
<?php
session_start();
if(isset($_SESSION['pgvisit']))
{
    $_SESSION['pgvisit']=$_SESSION['pgvisit']+1;
    echo "you are visiting this page for ".$_SESSION['pgvisit'] ,"times";
}
else
{
    $_SESSION['pgvisit']=1;
    echo "You are visiting this page for the 1st time";
    echo "\n",$_SESSION['pgvisit'];
}
session_destroy();
echo "\nsession destroyed ";
?>

---------------------------------
<?php
$servername="localhost";
$username="root";
$password=" ";
$dbname="studentdb";

$conn=new mysqli($servername,$username,$password,$dbname);
if($conn->connect_error)
{
    die("connection failed " .$conn->connect_error);
}
else
{
    echo "connected successfully";
}

$sql="select * from students ";
$result =$conn->query($sql);

if($result ->num_rows>0)
{
    while($_row=$result)
}

$conn->close();
?>
