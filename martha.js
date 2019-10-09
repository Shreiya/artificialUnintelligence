var five = require("johnny-five");//getting j5 on board

const Leap = require('leapjs');
const LeapFrame = require('./leapFrame');

var controller = Leap.loop({enableGestures:true}, function(frame){
    var currentFrame = frame;
    // var previousFrame = controller.frame(1);
    // var tenFramesBack = controller.frame(10);
});

//const controller = new Leap.Controller({ enableGestures: true });
var board = new five.Board();//declaring the function that will be used to control everything

board.on("ready", function() {//when the board is on. This is the main function.

  //console.log("in");

  var servoLeft = new five.Servo({
     pin: 9,
     range: [0,180],
     startAt: 0,
     fps: 200
    });

    var servoRight = new five.Servo({
       pin: 10,
       range: [0,180],
       startAt: 0,
       fps: 200
      });

  var servoMiddle = new five.Servo({
     pin: 11,
     range: [0,180],
     startAt: 0,
     fps: 200
    });

    var servoTop = new five.Servo({
      pin: 5,
      range: [0, 180],
      startAt: 0
    });

controller.on('frame', (data) => {

    console.log("LEAP RUNNING");
  //  console.log(i);
    frame = new LeapFrame(data);
    if (frame.valid) {
      let valX = mapVal (frame.palmPosition.x, -200,200,1,179, true);
      let valY = mapVal (frame.palmPosition.y, 30,300,0,180, true);
      let valZ = mapVal (frame.palmPosition.z, -200,200,0,180, true);
      console.log(valX);

      // if(valY > 180) valY = 180;
      // else if (valY <= 0) valY = 0;
      servoLeft.to(valZ);
      servoMiddle.to(valX);
      servoRight.to(valZ);
      // servoLeft.to(valZ);
      // servoRight.to(valZ);
      // servoTop.to(valX);
    }
});


});

let mapVal = (value, istart, istop, ostart, ostop, limits) => {
    let returnVal = ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
    if(limits === true) {
      if(returnVal > ostop) returnVal = ostop;
      else if(returnVal < ostart) returnVal = ostart;
    }
    return returnVal;
}
