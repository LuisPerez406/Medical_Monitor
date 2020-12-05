<?php
    $conexion = mysqli_connect('localhost','root','root');//conexion con BD
    mysqli_select_db($conexion,"proyecto"); //BD seleccionada
    if(!$conexion){ //si no se dio la conexion 
        die('La conexion no se ha podido realizar.'.mysqli_error());
    }
    else{   //si se dio la conexión, entonces:
        session_start();
        $id_individual = $_POST["id_individual"];       //proviene del modulo
        $hora1 = $_POST["hora1"];
        $BPM1 = $_POST["BPM1"];
        $IBI1 = $_POST["IBI1"];
        $hora2 = $_POST["hora2"];
        $BPM2 = $_POST["BPM2"];
        $IBI2 = $_POST["IBI2"];

        if($id_individual == 2455910){
            mysqli_query($conexion, "INSERT INTO analisis1 (id_individual, hora1, BPM1, IBI1, hora2, BPM2, IBI2) 
            VALUES ('$id_individual', '$hora1', '$BPM1', '$IBI1', '$hora2', '$BPM2', '$IBI2')");
            echo "Datos enviados correctamente";
            echo $id_individual; echo " ";
            echo $hora1; echo " ";
            echo $BPM1; echo " ";
            echo $IBI1; echo " ";
            echo $hora2; echo " ";
            echo $BPM2; echo " ";
            echo $IBI2; echo " ";
        }
        elseif($id_individual == 15926){
            mysqli_query($conexion, "INSERT INTO analisis2 (id_individual, hora1, BPM1, IBI1, hora2, BPM2, IBI2) 
            VALUES ('$id_individual', '$hora1', '$BPM1', '$IBI1', '$hora2', '$BPM2', '$IBI2')");
            echo "Datos enviados correctamente";
            echo $id_individual; echo " ";
            echo $hora1; echo " ";
            echo $BPM1; echo " ";
            echo $IBI1; echo " ";
            echo $hora2; echo " ";
            echo $BPM2; echo " ";
            echo $IBI2; echo " ";
        }


        if($_SESSION['id_pac']==2455910){
            $que;
            $que = "SELECT analisis1.id_individual, hora1, BPM1, IBI1, hora2, BPM2, IBI2
            FROM pacientes1 INNER JOIN analisis1 ON pacientes1.id = analisis1.id_individual";
        }
        if($_SESSION['id_pac'] == 15926){
            $que;
            $que = "SELECT analisis2.id_individual, hora1, BPM1, IBI1, hora2, BPM2, IBI2
            FROM pacientes2 INNER JOIN analisis2 ON pacientes2.id = analisis2.id_individual";
        }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.5.0/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/mdbootstrap/4.19.0/css/mdb.min.css" rel="stylesheet">
</head>
<body style="background: linear-gradient(to right, #34495e, #ebedef);">

<div style="background: #c8d0f2">
        <table class="table table-bordered">
        <thead><!--  -->
            <tr><!-- Fila de celdas -->
                <th scope="col">Id del paciente</th><!-- nombre de celda -->
                <th scope="col">Hora 1:</th><!-- nombre de celda -->
                <th scope="col">BPM 1:</th><!-- nombre de celda -->
                <th scope="col">IBI 1:</th><!-- nombre de celda -->
                <th scope="col">hora 2:</th><!-- nombre de celda -->
                <th scope="col">BPM 2:</th><!-- nombre de celda -->
                <th scope="col">IBI 2:</th><!-- nombre de celda -->
            </tr>
        </thead>
</HTML>
<?php


    $consulta= $conexion->query($que);
    if($consulta){
        while($fila = mysqli_fetch_array($consulta)){ 
        
?>
<tbody>
    <tr>
        <td><?php echo $fila['id_individual'] ?> </td>   <!-- Imprime el ID que hay en la BD -->
        <td><?php echo $fila['hora1']  ?> </td> <!-- Imprime la hora1 que hay en la BD -->
        <td><?php echo $fila['BPM1']  ?> </td> <!-- Imprime el BPM1 que hay en la BD -->
        <td><?php echo $fila['IBI1']  ?> </td> <!-- Imprime el IBI1 que hay en la BD -->
        <td><?php echo $fila['hora2']  ?> </td> <!-- Imprime la hora 2 que hay en la BD -->
        <td><?php echo $fila['BPM2']  ?> </td> <!-- Imprime el BPM2 que hay en la BD -->
        <td><?php echo $fila['IBI2']  ?> </td> <!-- Imprime el IBI2 que hay en la BD -->
    </tr>
</tbody>
<?php
            }
          }
          
          else{
              echo "No se ha podido realizar la consulta"; //Mensaje de error
          }
?>
</body>
</html>
<?php       
mysqli_close($conexion);

?>
