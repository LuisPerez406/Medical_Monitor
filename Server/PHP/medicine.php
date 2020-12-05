<?php
    $conexion = mysqli_connect('localhost','root','root');
    mysqli_select_db($conexion,"proyecto"); 
    if(!$conexion){ 
        die('La conexion no se ha podido realizar.'.mysqli_error());
    }
    else{  
        session_start();
        $id_del_paciente = $_SESSION['id_pac'];  //recibo id del paciente
        $ID= $_SESSION['id'];  //recibo id del médico
        $medicamento = $_POST["medicina"];
        $cantidad = $_POST["cantidad"];
        $periodo = $_POST["periodo"];
        $duracion = $_POST["duracion"];
        $hora = $_POST["hora"];
        if($id_del_paciente == 2455910 && $ID == 17110224){ //si es un paciente de pacientes1, y este es su ID (todo correspondiente a medico1)
            $ins = "INSERT INTO medicinas1 (medicina, cantidad, periodo, duracion, id_usuario1, hora)
            VALUES ('$medicamento', '$cantidad', '$periodo', '$duracion', '$id_del_paciente', '$hora')";
            
            if($conexion->query($ins) == TRUE){ 
                echo "Registrado Exitosamente";
            }
            else{
                echo "Error";
            }
        }

        if($id_del_paciente == 987654 && $ID == 17110236){ //si es un paciente de pacientes2, y este es su ID (todo correspondiente a medico2)
            $ins = "INSERT INTO medicinas2 (medicina, cantidad, periodo, duracion, id_usuario2)
            VALUES ('$medicamento', '$cantidad', '$periodo', '$duracion', '$id_del_paciente')";
            
            if($conexion->query($ins) == TRUE){ 
                echo "Registrado Exitosamente";
            }
            else{
                echo "Error";
            }
        }


    }

?>
