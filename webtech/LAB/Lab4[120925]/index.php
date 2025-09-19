
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form method="POST" action="mystd.php">
        Name    :   <input type="text" name="std_name"/> </br>
        Email   :   <input type="email" name="std_email" /> </br>
        <input type="submit" name="submit" value="Insert" />
    </form>
    <?php
    if(isset($_REQUEST['submit'])){
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "mydatabase";

        //Create Connection
        $conn = new mysqli($servername, $username,$password,$dbname);

        // Check Connection
        if($conn->connect_error){
            die("Connection failed.".$conn->connect_error);
        }
        else{
            $sql = "INSERT INTO student_db(std_name,std_email) VALUES('".$_POST['std_name']."','".$_POST['std_email']."')";
            if($conn->query($sql) === TRUE){
                echo "New Record created successfully";
            }
            else{
                echo "Error:".$sql."<br>".$conn->error;
            }
        }
        $conn->close();
    }
    ?>
</body>
</html>
mystd.php
External
Displaying mystd.php.