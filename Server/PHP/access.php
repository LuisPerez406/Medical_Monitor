<?php
    $conexion = mysqli_connect('localhost','root','root'); 
    mysqli_select_db($conexion,"proyecto"); 
    if(!$conexion){  
        die('La conexion no se ha podido realizar.'.mysqli_error());
    }
    else{
        session_start();  //manda y recibe datos a traves de variable $SESSION mandamos id del medico
        // obtenemos lo del formulario
        $id = $_POST["registro"]; 
        $contra = $_POST["contra"];
        
        $_SESSION['id']=$id; //almacenamos id en session
        $sql = 'Select id from medicos where id = "'.$_SESSION['id'].'" and pass = "'.$contra.'";';
        if($res=$conexion->query($sql)){
            $buscarUser = $res->num_rows;
            if($buscarUser >0){

?>

            <!DOCTYPE html>
            <html lang="en">
            <head>
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <title>Document</title>
                <link rel="stylesheet" href="../ArchivosCSS/regis.css"> 
                <link href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.5.0/css/bootstrap.min.css" rel="stylesheet">
                <link href="https://cdnjs.cloudflare.com/ajax/libs/mdbootstrap/4.19.0/css/mdb.min.css" rel="stylesheet">
            </head>

            <body>
                <!-- Contenedor de título -->
                <div class="card-header" style = "background: #1834af"> 
                    <h3 class="row justify-content-center" style="color: white; font: oblique bold 80px arial;"><em><b>Pacientes</b></em></h3>
                </div>
            <div style="background: #c8d0f2">
                <table class="table table-bordered">
                <thead><!--  -->
                    <tr><!-- Fila de celdas -->
                        <th scope="col">Nombre</th><!-- nombre de celdas -->
                        <th scope="col">Apellido paterno</th><!-- nombre de celdas -->
                        <th scope="col">Apellido materno</th><!-- nombre de celdas -->
                        <th scope="col">Celular</th><!-- nombre de celdas -->
                        <th scope="col">CURP</th><!-- nombre de celdas -->
                    </tr>
                </thead>
            </html>
<!-- ------------------------------------------------------------------------------- -->
            <?php
            $que;
            if($id == 17110224){
                $que = "SELECT pacientes1.nombre, apellido_paterno, apellido_materno, celular, curp 
                FROM medicos INNER JOIN pacientes1 ON medicos.id = pacientes1.id_medico1";
            }
            if($id == 17110236){
                $que = "SELECT pacientes2.nombre, apellido_paterno, apellido_materno, celular, curp
                FROM medicos INNER JOIN pacientes2 ON medicos.id = pacientes2.id_medico2";

            }
            $consulta= $conexion->query($que);
            if($consulta){
                while($fila = mysqli_fetch_array($consulta)){ 
        
            ?>
            <tbody>
                <tr>
                    <td><?php echo $fila['nombre'] ?> </td>  
                    <td><?php echo $fila['apellido_paterno']  ?> </td> 
                    <td><?php echo $fila['apellido_materno']  ?> </td> 
                    <td><?php echo $fila['celular']  ?> </td> 
                    <td><?php echo $fila['curp']  ?> </td> 
                </tr>
            </tbody>
            <?php
                }
            }
          
            else{
              echo "No se ha podido realizar la consulta"; 
            }
            ?>
            </table>
            <div style="background: linear-gradient(to right, #34495e, #ebedef);">
                <a type="submit" href="registrar.php" style="background-color: blue;
                text-decoration: none; color: red; font-size: x-large;border: 5px inset black;
                margin-left: 1250px;" >Registrar</a><br><br>



            <form action="mostrar_paciente.php" method="POST">
                <input type="text" name="curp_paciente" id="curp_paciente" placeholder="Ingrese CURP del paciente para ver sus todos sus datos" style="width: 430px; height: 30px; margin-left: 850px;">
                <input type="submit" value="Buscar">
            </form>
            </div>
            </div>

            <html>
          
            </body>
            </html>
            <?php
            }
            else{  //si no se encuentra el registro/contraseña
                echo "Error, el usuario o contraseña no son validos";
            }
        }
    }
?>
