<!DOCTYPE html>
<html lang="no">
<head>
    <meta charset="UTF-8">
    <meta name="author" content="Silje Stadheim">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Oppgave 2</title>
    <script>
        window.onload = oppstart;

        var grense = [];
        //= [Navn på studiet, studiested, poengsum, kjønnspeng, antall år]
        grense[0] = ["Ingeniørvitenskap og IKT","NTNU Trondheim",52.6,"ja",5];
        grense[1] = ["Energi og miljø","NTNU Trondheim",53.9,"nei",5];
        grense[2] = ["Kommunikasjonsteknologi","NTNU Trondheim",55.2,"ja",5];
        grense[3] = ["Bygg- og miljøteknikk","NTNU Trondheim",52.8,"nei",5];
        grense[4] = ["Datateknologi","NTNU Trondheim",57.2,"ja",5];
        grense[5] = ["Datavitenskap","NMBU Ås",0,"nei",5];
        grense[6] = ["Ingeniør, data","NTNU Trondheim",51.9,"ja",3];
        grense[7] = ["Ingeniør, elektro","NTNU Trondheim",46,"ja",3];
        grense[8] = ["Elektronisk systemdesign og innovasjon","NTNU Trondheim",54,"ja",5];
        grense[9] = ["Produktutvikling og produksjon","NTNU Trondheim",52.3,"ja",5];

        function oppstart() {
            d("btnReg").onclick = beregnPoeng;
        }

        function beregnPoeng() {
            var snitt = parseFloat(d("nbrSnitt").value);
            var tillegg = parseFloat(d("nbrTillegg").value);
            var poeng = (snitt*10 + tillegg).toFixed(1);
            var kjonn = radioForm.elements.namedItem("radKnapp").value;
            var kjonnspoeng = parseFloat(poeng) + 2 ;

            d("txtUtskrift").innerHTML = "<h3> Du søker med " + poeng + " poeng </h3>";
            for(var i=0; i<grense.length; i++) {
                var studiet = document.createElement("span");
                studiet.innerHTML = grense[i][0] + " " + grense[i][2] + "p" + "<br/>";
                if(grense[i][2] < poeng) {
                    studiet.style.color = "green";
                }
                else if(grense[i][2] < kjonnspoeng) {
                    console.log(poeng + " " + kjonnspoeng);
                    if(kjonn === "kvinne") {
                        studiet.style.color = "purple";
                        console.log(grense[i][0]+ grense[i][2] + " kjonnspoeng: " + kjonnspoeng);
                    }
                    else if(kjonn === "mann") {
                        studiet.style.color = "red";
                    }
                    else {
                        studiet.innerHTML = "Ops! Her gikk noe galt <br/>";
                    }
                }
                else if(grense[i][2] > poeng) {
                    studiet.style.color = "red";
                }
                else{
                    studiet.innerHTML = "Ops! Her gikk noe galt <br/>";
                }
                d("txtUtskrift").appendChild(studiet);
            }

            //sjekker om alle input feltene er fyllt ut, hvis ikke kommer det en feilmelding.
            if(isNaN(snitt) === true ||isNaN(tillegg) === true || d("mann").checked === false && d("kvinne").checked === false) {
                d("txtUtskrift").innerHTML = "Vennligst fyll ut all informasjonen.";
            }
        }

        //setter inn document.getElementById så jeg slipper å skrive de inn
        function d(elm) { //elm for element
            return document.getElementById(elm);
        }

    </script>
    <style>
        body {
            background-image: url(bakgrunn.jpg);
            background-size: auto;
        }
        .innpakning {
            margin: auto;;
            padding: 10px;
            text-align: center;
        }


    </style>
</head>
<body>

<div class="innpakning">
    <h2>Registrer dine studiepoeng og se hvilke studier du kommer inn på</h2>

    <div class="inputs">
    Skolesnitt:<br/><input type="number" id="nbrSnitt"><br/>
    Realfagspoeng:<br/><input type="number" id="nbrTillegg"><br/>
    <form name="radioForm">
        Kjønn:<br/>
        <input type="radio" name="radKnapp" id="mann" value="mann">Mann<br>
        <input type="radio" name="radKnapp" id="kvinne" value="kvinne">Kvinne<br>
    </form> <br>
    <button type="button" id="btnReg">Beregn</button>
        </div>

    <p id="txtUtskrift"></p>
</div>


</body>
</html>
