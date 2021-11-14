// Your web app's Firebase configuration
  
  
  
    

$(document).ready(function(){
	var database = firebase.database();
	
	var portao;
	var led5;
	var led;
	var led1;
	var led2;
	var led3;
	
	var led4;
	var led6;
	
	
	database.ref().on("value", function(snap){
		portao = snap.val().portao;
		led5 = snap.val().led5;
		led = snap.val().led;
		led1 = snap.val().led1;
		led2 = snap.val().led2;
		led3 = snap.val().led3;
		led4 = snap.val().led4;
		led6 = snap.val().led6;
		
		
		
		
		if(portao == "0"){
			document.getElementById("unact").style.display = "none";
			document.getElementById("act").style.display = "block";
		} else {
			document.getElementById("unact").style.display = "block";
			document.getElementById("act").style.display = "none";
		}
		
		if(led5 == "0"){
			document.getElementById("unact1").style.display = "none";
			document.getElementById("act1").style.display = "block";
		} else {
			document.getElementById("unact1").style.display = "block";
			document.getElementById("act1").style.display = "none";
		}
		
		
		
		if(led == "0"){
			document.getElementById("unact2").style.display = "none";
			document.getElementById("act2").style.display = "block";
		} else {
			document.getElementById("unact2").style.display = "block";
			document.getElementById("act2").style.display = "none";
		}
		
		if(led1 == "0"){
			document.getElementById("unact3").style.display = "none";
			document.getElementById("act3").style.display = "block";
		} else {
			document.getElementById("unact3").style.display = "block";
			document.getElementById("act3").style.display = "none";
		}
		
		if(led2 == "0"){
			document.getElementById("unact4").style.display = "none";
			document.getElementById("act4").style.display = "block";
		} else {
			document.getElementById("unact4").style.display = "block";
			document.getElementById("act4").style.display = "none";
		}
		if(led3 == "0"){
			document.getElementById("unact5").style.display = "none";
			document.getElementById("act5").style.display = "block";
		} else {
			document.getElementById("unact5").style.display = "block";
			document.getElementById("act5").style.display = "none";
		}
		
		
		if(led4 == "0"){
			document.getElementById("unact6").style.display = "none";
			document.getElementById("act6").style.display = "block";
		} else {
			document.getElementById("unact6").style.display = "block";
			document.getElementById("act6").style.display = "none";
		}
		if(led6 == "0"){
			document.getElementById("unact7").style.display = "none";
			document.getElementById("act7").style.display = "block";
		} else {
			document.getElementById("unact7").style.display = "block";
			document.getElementById("act7").style.display = "none";
		}
		
	});

	
	$(".toggle-btn").click(function(){
		var firebaseRef = firebase.database().ref('portao');
		if(portao == "false"){
			firebaseRef.set("true");
			lampRef = "true";
		} else {
			firebaseRef.set("false");
			portao = "false";
		}
	})
	$(".toggle-btn1").click(function(){
		var firebaseRef = firebase.database().ref().child("led5");
		if(led5 == "0"){
			firebaseRef.set("1");
			led5 = "1";
		} else {
			firebaseRef.set("0");
			led5 = "0";
		}
	})
	
	
	$(".toggle-btn2").click(function(){
		var firebaseRef = firebase.database().ref().child("led");
		if(led == "0"){
			firebaseRef.set("1");
			led = "1";
		} else {
			firebaseRef.set("0");
			led = "0";
		}
	})
	$(".toggle-btn3").click(function(){
		var firebaseRef = firebase.database().ref().child("led1");
		if(led1 == "0"){
			firebaseRef.set("1");
			led1 = "1";
		} else {
			firebaseRef.set("0");
			led1 = "0";
		}
	})
	
	$(".toggle-btn4").click(function(){
		var firebaseRef = firebase.database().ref().child("led2");
		if(led2 == "0"){
			firebaseRef.set("1");
			led2 = "1";
		} else {
			firebaseRef.set("0");
			led2 = "0";
		}
	})
	
	$(".toggle-btn5").click(function(){
		var firebaseRef = firebase.database().ref().child("led3");
		if(led3 == "0"){
			firebaseRef.set("1");
			led3 = "1";
		} else {
			firebaseRef.set("0");
			led3 = "0";
		}
	})
	
	
	$(".toggle-btn6").click(function(){
		var firebaseRef = firebase.database().ref().child("led4");
		if(led4 == "0"){
			firebaseRef.set("1");
			led4 = "1";
		} else {
			firebaseRef.set("0");
			led4 = "0";
		}
	})
	
	$(".toggle-btn7").click(function(){
		var firebaseRef = firebase.database().ref().child("led6");
		if(led6 == "0"){
			firebaseRef.set("1");
			led6 = "1";
		} else {
			firebaseRef.set("0");
			led6 = "0";
		}
	})
	
	
});





function TocarMusica(){
    var audio1 = new Audio();
    audio1.src = "son/Clik.mp3";
    audio1.play();
}

function renderTime() {
	var currentTime = new Date();
	var diem = "AM";
	var h = currentTime.getHours();
	var m = currentTime.getMinutes();
    var s = currentTime.getSeconds();
	setTimeout('renderTime()',1000);
    if (h == 0) {
		h = 12;
	} else if (h > 12) { 
		h = h - 12;
		diem="PM";
	}
	if (h < 10) {
		h = "0" + h;
	}
	if (m < 10) {
		m = "0" + m;
	}
	if (s < 10) {
		s = "0" + s;
	}
    var myClock = document.getElementById('clockDisplay');
	myClock.textContent = h + ":" + m + ":" + s + " " + diem;
	myClock.innerText = h + ":" + m + ":" + s + " " + diem;
}
renderTime();



