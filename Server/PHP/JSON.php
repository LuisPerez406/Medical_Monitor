<?php
function connectDB(){

   $conexion = mysqli_connect("localhost", "root", "root", "proyecto");
    if($conexion){
    }
    else{
        echo 'Ha sucedido un error inesperado en la conexión de la base de datos';
    }   
    return $conexion;
}

function disconnectDB($conexion){
    $close = mysqli_close($conexion);
    return $close;
}
 //Creamos la conexión con la función anterior
 $conexion = connectDB();

$sql = "SELECT * FROM medicinas1";
mysqli_set_charset($conexion, "utf8");
if(!$result = mysqli_query($conexion, $sql)) die();
$clientes = array(); 
    while($row = mysqli_fetch_array($result))
    {
        $medicina=$row['medicina'];
        $cantidad=$row['cantidad'];
        $periodo=$row['periodo'];
        $duracion=$row['duracion'];
        $hora = $row["hora"];

        $clientes[] = array('medicina'=> $medicina, 'cantidad'=> $cantidad, 'periodo'=> $periodo,
        'duracion'=> $duracion, 'id_recibir'=> $id_recibir, 'hora' => $hora);
    }

    disconnectDB($conexion); //desconectamos la base de datos

  //Creamos el JSON
    $json_string = json_encode($clientes);
    echo $json_string;

?>
