const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
</head>
<body>
    <center>
        <h1>IoT</h1>  
        <h2>Question 7 Servo motor</h2>
    </center>
    <br>
    <div>
        <center>
            <input type="range" style="width: 500px; height: 220px;"  min="0" max="180"  value="90" id="slidbar">
        </center>
      </div>
    <center>
      <span>value: </span>
    <span id="f"></span>
    </center> 
      <script>
          function sendData(pos) {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              console.log(this.responseText);
            }
          };
          xhttp.open("GET", "setPOS?servoPOS="+pos, true);
          xhttp.send();
          } 

          var slide = document.getElementById("slidbar");
          var y = document.getElementById("f");
          y.innerHTML = slide.value;
          slide.oninput = function(){
            slide.value = this.value;  
            y.innerHTML = this.value;
            sendData(y.innerHTML);
          }
      </script>
</body>
</html>
)=====";
