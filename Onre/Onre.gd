extends CharacterBody2D

var playerspeed
const SPEED = 150 #300
const JUMP_VELOCITY = 1.5 
var Onreface
var attacking 
var onfloor
var currentstate
var weapon_selection
var start
var run
var alignment
var mana

var customMachine =  preload("res://Scripts/OnreStateMachine.gd")
var wp = load("res://Scripts/WeaponSelectionCode.gd")
var wp_obj = wp.new()
var mystate = AttackState.new()
var jumpclock = Timer.new()
var attackclock = Timer.new()
var manaclock = Timer.new()

@onready var life = 0

enum playerstate {
	idle,
	idleleft,
	walk,
	walkleft,
	fall,
	attack,
	attackright,
	runright,
	runleft

}



func _onready():
	attacking = false
	onfloor = false
	jumpclock.one_shot = true
	attackclock.one_shot = true
	run = false
	alignment = 0.0
	mana = 0.0
	weapon_selection = 0
	playerspeed = SPEED*2
	currentstate = playerstate.fall
	add_child(jumpclock)
	add_child(attackclock)




func JumpingState(delta):
	#print("We are in the jumping state")
	velocity -= (JUMP_VELOCITY)*get_gravity() * delta


func _physics_process(delta):
	#Add the gravity.	
	#var test = get_node("Onreani")
	#var state_machine = $AnimationTree["parameters/playback"]
	
	
	attacking = false
	onfloor = is_on_floor()

	
	
	#print(onfloor)
	if($Onre.flip_h == true):
		Onreface == true
	else:
		Onreface = false
		


	

	
		
	if not is_on_floor():
		velocity += get_gravity() * delta
		currentstate = playerstate.fall
	elif is_on_floor() and Onreface == false:
		if currentstate != playerstate.attack:
			currentstate = playerstate.idle
	elif is_on_floor() and Onreface == true:
		if currentstate != playerstate.attack:
			currentstate = playerstate.idleleft
	
	
		
	if Input.is_action_pressed("left") and run == false:
		Onreface = true
		#attacking = false
		#state_machine.travel("walkleft")
		$Onre.flip_h = true
		if(onfloor == true):
			currentstate = playerstate.walkleft
	
	
	
	elif Input.is_action_just_released("left"):
#		state_machine.travel("idleleft")

		$Onreani.stop()
		if(onfloor == true):
			currentstate = playerstate.idleleft
		
	if Input.is_action_pressed("right") and run == false:
		Onreface = false
		$Onre.flip_h = false
		#attacking = false
		#state_machine.travel("walk")
		if(onfloor == true):
			currentstate = playerstate.walk
			
	elif Input.is_action_just_released("right"):
	#	state_machine.travel("idle")
		$Onreani.stop()
		if(onfloor == true):
			currentstate = playerstate.idle
	
	if Input.is_action_pressed("runleft") and is_on_floor():
		run = true
		$Onre.flip_h = true
		currentstate = playerstate.runleft
		print("BOO")
	elif Input.is_action_just_released("runleft"):
		run = false
		$Onreani.play("idleleft")
		
	elif Input.is_action_pressed("runright") and is_on_floor():
		run = true
		$Onre.flip_h = false
		currentstate = playerstate.runright
	elif Input.is_action_just_released("runright"):
		run = false
		$Onreani.play("idle")
		
	
	else:
		run = false
		
	
	if Input.is_action_just_pressed("jump") and is_on_floor():
		
		jumpclock.start(0.7)
		if(Onreface == false):
			currentstate = playerstate.fall
			
		elif(Onreface == true):
			currentstate = playerstate.fall
		
	if Input.is_action_just_pressed("select"):
		weapon_selection = wp_obj.WeaponSelection(weapon_selection)
		
		
	if Input.is_action_just_pressed("enter"):
		if attackclock.time_left < 1:
			currentstate = playerstate.attack
			attackclock.start(.5)
	
	

		
	if Input.is_action_just_pressed("power"):
		print("A Power is being selected")
		pass
	#print("ATTACK CLOCK:",attackclock.time_left)
	
	print("Playerstate", currentstate)	

	if(jumpclock.time_left > 0):
		JumpingState(delta)
	#print(currentstate)
	match currentstate:
		
		playerstate.idle:
			$Onreani.play("idle")
			
		playerstate.idleleft:
			$Onreani.play("idleleft")
		
		playerstate.runleft:
			$Onreani.play("run")
		
		playerstate.runright:
			$Onreani.play("run")
		
		
		playerstate.walk:
			$Onreani.play("walk")
			#test.play("walk")
			$Onre.flip_h = false
			
			pass
		
		playerstate.walkleft:
			$Onreani.play("walk")
			$Onre.flip_h = true
			
		playerstate.attack:

			if weapon_selection == 0:
				$Onreani.play("knife")	
			elif weapon_selection == 1:
				$Onreani.play("knifelo")
			elif weapon_selection == 2:
				$Onreani.play("knifest")
			elif weapon_selection == 3:
				$Onreani.play("screech")
			if attackclock.time_left == 0:
				currentstate = playerstate.idle
		playerstate.fall:
			$Onreani.play("fall")
		_:
			
			pass
				
	#print(currentstate)	
	#print("Wepone selected:" , weapon_selection)
	#if Input.is_action_pressed("left"):
	#	Onreface = false
		#attacking = false
	#	state_machine.travel("walkleft")
	#elif Input.is_action_just_released("left"):
	#	state_machine.travel("idleleft")
		
		
	#elif Input.is_action_pressed("right"):
	#	Onreface = true
	#	mystate.TestMethod()
		#attacking = false
	#	state_machine.travel("walk")
	#elif Input.is_action_just_released("right"):
	#	state_machine.travel("idle")
	
		
#	if Input.is_action_just_pressed("enter"):
		#attacking = true
	#	if Onreface == false:
	#		state_machine.travel("attackleft")
	#	else:
	#		state_machine.travel("attack")
		
	#elif Input.is_action_just_released("enter") and Onreface == true:
#		state_machine.travel("idle")
#	elif Input.is_action_just_released("enter") and Onreface == false:
	#	state_machine.travel("idleleft")
		
	
		
	
	# Get the input direction and handle the movement/deceleration.
	# As good practice, you should replace UI actions with custom gameplay actions.
	var direction = Input.get_axis("left", "right")
	if direction and run == false:
		velocity.x = direction * SPEED
	
	elif direction and run == true:
		velocity.x = direction * playerspeed
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)
	
	#print(Onreface)
	#print("Jump Clock:",jumpclock.time_left)	
		
	
	
	move_and_slide()
