<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registrar</title>
    <link rel="stylesheet" href="../ArchivosCSS/registro_diseño.css">
</head>

<body>
    <header>
        <h1><strong><em>Registrar</em></strong></h1>
    </header>    
    <main>
        
<?php
session_start();  //recibimos datos (id)
    $ID=$_SESSION['id'];
    
?>
        <form name="formul" action="../../proyecto/ArchivosPHP/registro.php" method="POST"><br>
            <div>
                 <label>ID del paciente:</label>
                <input type="number" name="id_paciente" id="id_paciente" class="campos">
                <p class="titulos_campos">Datos personales del paciente</p>
                <label>Nombre del paciente:</label><label style="margin-left: 350px;">Apellido paterno</label><label style="margin-left: 280px;">Apellido materno</label><br>
                <input type="text" class="campos" name="nombre" id="nombre">
                <input style="margin-left: 80px;" type="text" class="campos" name="apellido_paterno" id="apellido_paterno">
                <input style="margin-left: 80px;" type="text" class="campos" name="apellido_materno" id="apellido_materno"><br><br>
                <label>Fecha de nacimiento: </label><label style="margin-left: 350px;">CURP:</label><br>
                <input type="date" class="campos" name="f_nacimiento" id="f_nacimiento">
                <input type="text" class="campos" style="margin-left: 80px;" name="curp" id="curp"><br><br>
                <label>Edad:</label><label style="margin-left: 450px;">Sexo:</label><label style="margin-left: 380px;">Estado civil:</label><br>
                <input type="number" class="campos" name="edad" id="edad">
                <input style="margin-left: 100px;" type="radio" name="sexo" id="sexo" value="masculino">Masculino
                <input style="margin-left: 20px;" type="radio" name="sexo" id="sexo" value="femenino">Femenino
                <input type="text" class="campos" style="margin-left: 180px;" name="edo_civil" id="edo_civil"><br><br>
                <label>Nacionalidad:</label><label style="margin-left: 430px;">País:</label><label style="margin-left: 380px;">Ciudad:</label><br>
                <input type="text" class="campos" name="nacionalidad" id="nacionalidad">
                <input type="text" class="campos" name="pais" id="pais" style="margin-left: 80px;">
                <input type="text" class="campos" name="ciudad" id="ciudad" style="margin-left: 80px;"><br><br>
                <label>Telefono:</label><label style="margin-left: 450px;">Celular:</label><label style="margin-left: 320px;">Correo electrónico:</label><br>
                <input type="number" name="telefono" id="telefono" class="campos">
                <input type="number" name="celular" id="celular" class="campos" style="margin-left: 80px;">
                <input type="email" name="email" id="email" class="campos" style="margin-left: 80px;"><br>
                <p class="titulo_secundario">Domicilio del paciente</p>

                <label style="margin-left: 43px;">Calle:</label>
                <input type="text" name="calle" id="calle" class="campos">
                <label style="margin-left: 40px;">#</label>
                <input type="number" name="num_calle" id="num_calle" class="campos"><br><br>
                <label>Entre calles: </label>
                <input type="text" name="calle1" id="calle1" class="campos"><label style="margin-left: 20px;"> y </label>
                <input type="text" name="calle2" id="calle2" class="campos" style="margin-left: 20px;"><br><br>
                <label style="margin-left: 25px;">Colonia:</label>
                <input type="text" name="colonia" id="colonia" class="campos"><label style="margin-left: 23px;">C.P.:</label>
                <input type="number" name="cp" id="cp" class="campos"><br><br>
                <!-- DATOS QUE SE LLENARÁN DE UN FAMILIAR DEL PACIENTE: -->
                <p class="titulos_campos">Datos de un familiar del paciente:</p>
                <label>Nombre del familiar:</label><label style="margin-left: 350px;">Apellidos del familiar:</label><label style="margin-left: 280px;">Parentesco:</label><br>
                <input type="text" class="campos" name="nombre_familiar" id="nombre_familiar">
                <input style="margin-left: 80px;" type="text" class="campos" name="apellidos_familiar" id="apellidos_familiar">
                <input style="margin-left: 80px;" type="text" class="campos" name="parentesco" id="parentesco"><br><br>
                <label>Fecha de nacimiento: </label><label style="margin-left: 350px;">CURP:</label><br>
                <input type="date" class="campos" name="f_nacimiento_familiar" id="f_nacimiento_familiar">
                <input type="text" class="campos" style="margin-left: 80px;" name="curp_familiar" id="curp_familiar"><br><br>
                <label>Edad:</label><label style="margin-left: 450px;">Sexo:</label><label style="margin-left: 380px;">Estado civil:</label><br>
                <input type="number" class="campos" name="edad_familiar" id="edad_familiar">
                <input style="margin-left: 100px;" type="radio" name="sexo_familiar" id="sexo_familiar" value="masculino">Masculino
                <input style="margin-left: 20px;" type="radio" name="sexo_familiar" id="sexo_familiar" value="femenino">Femenino
                <input type="text" class="campos" style="margin-left: 180px;" name="edo_civil_familiar" id="edo_civil_familiar"><br><br>
                <label>Nacionalidad:</label><label style="margin-left: 430px;">País:</label><label style="margin-left: 380px;">Ciudad:</label><br>
                <input type="text" class="campos" name="nacionalidad_f" id="nacionalidad_f">
                <input type="text" class="campos" name="pais_f" id="pais_f" style="margin-left: 80px;">
                <input type="text" class="campos" name="ciudad_f" id="ciudad_f" style="margin-left: 80px;"><br><br>
                <label>Telefono:</label><label style="margin-left: 450px;">Celular:</label><label style="margin-left: 320px;">Correo electrónico:</label><br>
                <input type="number" name="telefono_f" id="telefono_f" class="campos">
                <input type="number" name="celular_f" id="celular_f" class="campos" style="margin-left: 80px;">
                <input type="email" name="email_f" id="email_f" class="campos" style="margin-left: 80px;"><br>
                <p class="titulo_secundario">Domicilio del familiar del paciente</p>
                <label style="margin-left: 43px;">Calle:</label>
                <input type="text" name="calle_f" id="calle_f" class="campos">
                <label style="margin-left: 40px;">#</label>
                <input type="number" name="num_calle_f" id="num_calle_f" class="campos"><br><br>
                <label>Entre calles: </label>
                <input type="text" name="calle1_f" id="calle1_f" class="campos"><label style="margin-left: 20px;"> y </label>
                <input type="text" name="calle2_f" id="calle2_f" class="campos" style="margin-left: 20px;"><br><br>
                <label style="margin-left: 25px;">Colonia:</label>
                <input type="text" name="colonia_f" id="colonia_f" class="campos"><label style="margin-left: 23px;">C.P.:</label>
                <input type="number" name="cp_f" id="cp_f" class="campos"><br><br>
                <p class="titulos_campos">Datos médicos del paciente:</p>
                <label>Número de seguridad social:</label><label style="margin-left: 330px;">Afiliación</label><br>
                <input type="number" class="campos" name="nss" id="nss">
                <input type="text" class="campos" name="afiliacion" id="afiliacion" style="margin-left: 80px;"><br><br>
                <label>Tipo de sangre:</label><label style="margin-left: 420px;">Alergias:</label><label style="margin-left: 300px;">Alergias médicas:</label><br>
                <input type="text" class="campos" name="tipo_sangre" id="tipo_sangre">
                <input type="text" class="campos" name="alergias" id="alergias" style="margin-left: 80px;">
                <input type="text" class="campos" name="alergias_medicas" id="alergias_medicas" style="margin-left: 80px;"><br><br>
                <label>Problemas de salud crónicos:</label><label style="margin-left: 300px;">Antecedentes familiares:</label><br>
                <input type="text" class="campos" name="problemas_salud_cronicos" id="problemas_salud_cronicos">
                <input type="text" class="campos" name="antecedentes_familiares" id="antecedentes_familiares" style="margin-left: 80px;">
        </div>
        <input type="submit" value="Registrar" style="color: blue; background-color: rgb(128, 150, 223); width: 100px; height: 40px; font-size: large; font-weight: bold;margin-left: 1000px; border-radius: 5px;"><br><br>
        <br>
        </form><br><br>
    </main>
</body>
</html>
