
"use strict";

let ButtonEvent = require('./ButtonEvent.js');
let MotorPower = require('./MotorPower.js');
let WheelDropEvent = require('./WheelDropEvent.js');
let Led = require('./Led.js');
let DockInfraRed = require('./DockInfraRed.js');
let DigitalOutput = require('./DigitalOutput.js');
let KeyboardInput = require('./KeyboardInput.js');
let CliffEvent = require('./CliffEvent.js');
let BumperEvent = require('./BumperEvent.js');
let DigitalInputEvent = require('./DigitalInputEvent.js');
let Sound = require('./Sound.js');
let ControllerInfo = require('./ControllerInfo.js');
let SensorState = require('./SensorState.js');
let PowerSystemEvent = require('./PowerSystemEvent.js');
let RobotStateEvent = require('./RobotStateEvent.js');
let VersionInfo = require('./VersionInfo.js');
let ScanAngle = require('./ScanAngle.js');
let ExternalPower = require('./ExternalPower.js');
let AutoDockingAction = require('./AutoDockingAction.js');
let AutoDockingFeedback = require('./AutoDockingFeedback.js');
let AutoDockingGoal = require('./AutoDockingGoal.js');
let AutoDockingResult = require('./AutoDockingResult.js');
let AutoDockingActionResult = require('./AutoDockingActionResult.js');
let AutoDockingActionGoal = require('./AutoDockingActionGoal.js');
let AutoDockingActionFeedback = require('./AutoDockingActionFeedback.js');

module.exports = {
  ButtonEvent: ButtonEvent,
  MotorPower: MotorPower,
  WheelDropEvent: WheelDropEvent,
  Led: Led,
  DockInfraRed: DockInfraRed,
  DigitalOutput: DigitalOutput,
  KeyboardInput: KeyboardInput,
  CliffEvent: CliffEvent,
  BumperEvent: BumperEvent,
  DigitalInputEvent: DigitalInputEvent,
  Sound: Sound,
  ControllerInfo: ControllerInfo,
  SensorState: SensorState,
  PowerSystemEvent: PowerSystemEvent,
  RobotStateEvent: RobotStateEvent,
  VersionInfo: VersionInfo,
  ScanAngle: ScanAngle,
  ExternalPower: ExternalPower,
  AutoDockingAction: AutoDockingAction,
  AutoDockingFeedback: AutoDockingFeedback,
  AutoDockingGoal: AutoDockingGoal,
  AutoDockingResult: AutoDockingResult,
  AutoDockingActionResult: AutoDockingActionResult,
  AutoDockingActionGoal: AutoDockingActionGoal,
  AutoDockingActionFeedback: AutoDockingActionFeedback,
};
