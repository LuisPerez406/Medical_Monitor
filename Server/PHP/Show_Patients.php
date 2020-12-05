<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Datos del paciente</title>
    </head>
    <body style="background-color: cornflowerblue;">
        <h1 style="font-size: xx-large; color: rgb(228, 228, 240); text-align: center;">Los datos del paciente son:</h1>
    <?php
        $curp_paciente = $_POST["curp_paciente"];   //recibo el nombre del paciente

        $conexion = mysqli_connect('localhost','root','root');//conexion con BD
        mysqli_select_db($conexion,"proyecto"); //BD seleccionada
        if(!$conexion){ //si no se dio la conexion 
            die('La conexion no se ha podido realizar.'.mysqli_error());
            //die = mensaje de error, mysqli_error() y die muestran el error que tenemos
        }
        else{
            session_start();   //recibimos id
            $ID= $_SESSION['id'];
            if($ID == "17110224"){
                $consulta = mysqli_query($conexion,"SELECT curp FROM pacientes1");
                $encontrado=false;
                while($fila = mysqli_fetch_array($consulta)){
                    if($curp_paciente ==  $fila['curp']){
                        $encontrado=true;
                        break;
                    }
                }
                if($encontrado){  //encontró el nombre en BD.
                    $datos_encontrados = mysqli_query($conexion,"SELECT * FROM pacientes1");
                    while($fila = mysqli_fetch_array($datos_encontrados)){
                        if($curp_paciente ==  $fila['curp']){
    ?>
                        <div style="border: 5px blue inset;">
                            <h2>Datos personales:</h2>
                            <?php echo "Nombre: "; echo $fila["nombre"];?><br>
                            <?php echo "Apellidos: "; echo $fila["apellido_paterno"]; echo" "; echo $fila["apellido_materno"];?><br>
                            <?php echo "Fecha de nacimiento: "; echo $fila["f_nacimiento"]?><br>
                            <?php echo "CURP: "; echo $fila["curp"];?><br>
                            <?php echo "Edad: "; echo $fila["edad"];?><br>
                            <?php echo "Sexo: "; echo $fila["sexo"];?><br>
                            <?php echo "Estado civil: "; echo $fila["edo_civil"];?><br>
                            <?php echo "Nacionalidad: "; echo $fila["nacionalidad"];?><br>
                            <?php echo "País: "; echo $fila["pais"];?><br>
                            <?php echo "Ciudad: "; echo $fila["ciudad"];?><br>
                            <?php echo "Telefono: "; echo $fila["telefono"];?><br>
                            <?php echo "Celular: "; echo $fila["celular"];?><br>
                            <?php echo "Correo electrónico: "; echo $fila["email"];?><br>
                            <h2>Dirección del paciente</h2>
                            <?php echo "Calle: "; echo $fila["calle"];?><br>
                            <?php echo "Número: "; echo $fila["num_calle"];?><br>
                            <?php echo " Colonia: "; echo $fila["colonia"];?><br>
                            <?php echo "Código postal: "; echo $fila["cp"];?><br>
                            <?php echo "Entre calles: "; echo $fila["calle1"]; echo " y ";?>
                            <?php echo $fila["calle2"];?><br>
                        </div>
                        <div style="margin-left: 500px; margin-top: -465px; ">
                            <h2>Datos de un familiar: </h2>
                            <?php echo "Nombre: "; echo $fila["nombre_familiar"];?><br>
                            <?php echo "Apellidos: "; echo $fila["apellidos_familiar"]; echo" ";?><br>
                            <?php echo "Fecha de nacimiento: "; echo $fila["f_nacimiento_familiar"]?><br>
                            <?php echo "CURP: "; echo $fila["curp_familiar"];?><br>
                            <?php echo "Edad: "; echo $fila["edad_familiar"];?><br>
                            <?php echo "Sexo: "; echo $fila["sexo_familiar"];?><br>
                            <?php echo "Estado civil: "; echo $fila["edo_civil_familiar"];?><br>
                            <?php echo "Nacionalidad: "; echo $fila["nacionalidad_f"];?><br>
                            <?php echo "País: "; echo $fila["pais_f"];?><br>
                            <?php echo "Ciudad: "; echo $fila["ciudad_f"];?><br>
                            <?php echo "Telefono: "; echo $fila["telefono_f"];?><br>
                            <?php echo "Celular: "; echo $fila["celular_F"];?><br>
                            <?php echo "Correo electrónico: "; echo $fila["email_f"];?><br>
                            <h2>Dirección del familiar del paciente</h2>
                            <?php echo "Calle: "; echo $fila["calle_f"];?><br>
                            <?php echo "Número: "; echo $fila["num_calle_f"];?><br>
                            <?php echo " Colonia: "; echo $fila["colonia_f"];?><br>
                            <?php echo "Código postal: "; echo $fila["cp_f"];?><br>
                            <?php echo "Entre calles: "; echo $fila["calle1_f"]; echo " y ";?>
                            <?php echo $fila["calle2_f"];?><br>
                        </div>
                        <div style="margin-left: 1000px; margin-top: -465px; ">
                            <h2>Datos médicos del paciente:  </h2>
                            <?php echo "Número seguridad social: "; echo $fila["numero_seguridad_social"];?><br>
                            <?php echo "Afiliación: "; echo $fila["afiliacion"]; echo" ";?><br>
                            <?php echo "Tipo de sangre: "; echo $fila["tipo_sangre"]?><br>
                            <?php echo "Alergias: "; echo $fila["alergias"];?><br>
                            <?php echo "Alergias medicas: "; echo $fila["alergias_medicas"];?><br>
                            <?php echo "Problemas de salud crónicos: "; echo $fila["problemas_salud_cronicos"];?><br>
                            <?php echo "Antecedentes familiares: "; echo $fila["antecedentes_familiares"];?><br>
                            <?php echo "Id del usuario (del paciente): "; echo $fila["id"];
                            $_SESSION['id_pac'] = $fila['id']; 
                            ?><br>
                        </div>
                        <?php 
                        break;
                        }
                    }
                }
                else{
                    echo "El paciente no esta registrado, checar si se escribió correctamente";
                }
            }
            if($ID == "17110236"){
                $consulta = mysqli_query($conexion,"SELECT curp FROM pacientes2");
                $encontrado=false;
                while($fila = mysqli_fetch_array($consulta)){
                    if($curp_paciente ==  $fila['curp']){
                        $encontrado=true;
                        break;
                    }
                }
                if($encontrado){  //encontró el nombre en BD.
                    $datos_encontrados = mysqli_query($conexion,"SELECT * FROM pacientes2");
                    while($fila = mysqli_fetch_array($datos_encontrados)){
                        if($curp_paciente ==  $fila['curp']){
?>
                        <div style="border: 5px blue inset;">
                            <h2>Datos personales:</h2>
                            <?php echo "Nombre: "; echo $fila["nombre"];?><br>
                            <?php echo "Apellidos: "; echo $fila["apellido_paterno"]; echo" "; echo $fila["apellido_materno"];?><br>
                            <?php echo "Fecha de nacimiento: "; echo $fila["f_nacimiento"]?><br>
                            <?php echo "CURP: "; echo $fila["curp"];?><br>
                            <?php echo "Edad: "; echo $fila["edad"];?><br>
                            <?php echo "Sexo: "; echo $fila["sexo"];?><br>
                            <?php echo "Estado civil: "; echo $fila["edo_civil"];?><br>
                            <?php echo "Nacionalidad: "; echo $fila["nacionalidad"];?><br>
                            <?php echo "País: "; echo $fila["pais"];?><br>
                            <?php echo "Ciudad: "; echo $fila["ciudad"];?><br>
                            <?php echo "Telefono: "; echo $fila["telefono"];?><br>
                            <?php echo "Celular: "; echo $fila["celular"];?><br>
                            <?php echo "Correo electrónico: "; echo $fila["email"];?><br>
                            <h2>Dirección del paciente</h2>
                            <?php echo "Calle: "; echo $fila["calle"];?><br>
                            <?php echo "Número: "; echo $fila["num_calle"];?><br>
                            <?php echo " Colonia: "; echo $fila["colonia"];?><br>
                            <?php echo "Código postal: "; echo $fila["cp"];?><br>
                            <?php echo "Entre calles: "; echo $fila["calle1"]; echo " y ";?>
                            <?php echo $fila["calle2"];?><br>
                        </div>
                        <div style="margin-left: 500px; margin-top: -465px; ">
                            <h2>Datos de un familiar: </h2>
                            <?php echo "Nombre: "; echo $fila["nombre_familiar"];?><br>
                            <?php echo "Apellidos: "; echo $fila["apellidos_familiar"]; echo" ";?><br>
                            <?php echo "Fecha de nacimiento: "; echo $fila["f_nacimiento_familiar"]?><br>
                            <?php echo "CURP: "; echo $fila["curp_familiar"];?><br>
                            <?php echo "Edad: "; echo $fila["edad_familiar"];?><br>
                            <?php echo "Sexo: "; echo $fila["sexo_familiar"];?><br>
                            <?php echo "Estado civil: "; echo $fila["edo_civil_familiar"];?><br>
                            <?php echo "Nacionalidad: "; echo $fila["nacionalidad_f"];?><br>
                            <?php echo "País: "; echo $fila["pais_f"];?><br>
                            <?php echo "Ciudad: "; echo $fila["ciudad_f"];?><br>
                            <?php echo "Telefono: "; echo $fila["telefono_f"];?><br>
                            <?php echo "Celular: "; echo $fila["celular_F"];?><br>
                            <?php echo "Correo electrónico: "; echo $fila["email_f"];?><br>
                            <h2>Dirección del paciente</h2>
                            <?php echo "Calle: "; echo $fila["calle_f"];?><br>
                            <?php echo "Número: "; echo $fila["num_calle_f"];?><br>
                            <?php echo " Colonia: "; echo $fila["colonia_f"];?><br>
                            <?php echo "Código postal: "; echo $fila["cp_f"];?><br>
                            <?php echo "Entre calles: "; echo $fila["calle1_f"]; echo " y ";?>
                            <?php echo $fila["calle2_f"];?><br>
                        </div>
                        <div style="margin-left: 1000px; margin-top: -465px; ">
                            <h2>Datos médicos del paciente:  </h2>
                            <?php echo "Número seguridad social: "; echo $fila["nss"];?><br>
                            <?php echo "Afiliación: "; echo $fila["afiliacion"]; echo" ";?><br>
                            <?php echo "Tipo de sangre: "; echo $fila["tipo_sangre"]?><br>
                            <?php echo "Alergias: "; echo $fila["alergias"];?><br>
                            <?php echo "Alergias medicas: "; echo $fila["alergias_medicas"];?><br>
                            <?php echo "Problemas de salud crónicos: "; echo $fila["problemas_salud_cronicos"];?><br>
                            <?php echo "Antecedentes familiares: "; echo $fila["antecedentes_familiares"];?><br>
                            <?php echo "Id del usuario (del paciente): "; echo $fila["id"];
                            $_SESSION['id_pac'] = $fila['id']; 
                            ?><br>
                        </div>
                        <?php 
                        break;
                        }
                    }
                }
                else{
                    echo "El paciente no esta registrado, checar si se escribió correctamente";
                }
            }
        }





                        ?>
<br>

<form action="analisis_datos.php" method="POST" style="margin-top: 300px;">
<input type="submit" value="Mostrar resultados">
</form>

<form action="medicamento.php" method="POST" style="margin-top: 150px; text-align: left;
      border: 5px darkgray inset; margin-left: 400px; margin-right: 500px;"><br><br>
    <label style="font-size: xx-large; margin-left: 90px; color: darkred; font-weight: bold;">Recetar medicamento:</label><br><br>
    <label  style="margin-left: 70px;">Medicamento: </label>
    <input type="text" name="medicina" id="medicina" style="margin-left: 20px;"><br><br>
    <label style="margin-left: 100px;">Cantidad: </label>
    <input type="text" name="cantidad" id="cantidad"  style="margin-left: 20px;"><br><br>
    <label style="margin-left: 110px;">Periodo: </label>
    <input type="number" name="periodo" id="periodo" placeholder="En horas"  style="margin-left: 20px;"><br><br>
    <label style="margin-left: 100px;">Duración: </label>
    <input type="number" name="duracion" id="duracion" placeholder="En dias" style="margin-left: 20px;"><br><br>
    <label style="margin-left: 130px;">Hora: </label>
    <input type="number" name="hora" id="hora"  style="margin-left: 20px;"><br><br>
    <input type="submit" value="Recetar" style="margin-left: 180px;"><br><br>
</form><br><br>


</body>
</html>
