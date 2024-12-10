extends CharacterBody2D


const SPEED = 150 #300
const JUMP_VELOCITY = 1.1
var Onreface
var attacking 
var onfloor
var currentstate
var start

var customMachine =  preload("res://Scripts/OnreStateMachine.gd")
var mystate = AttackState.new()
var jumpclock = Timer.new()

enum playerstate {
	idle,
	idleleft,
	walk,
	walkleft,
	fall,
	attack,
	attackright,
	jump,
	jumpleft
}



func _onready():
	attacking = false
	onfloor = false
	jumpclock.one_shot = true
	add_child(jumpclock)


func JumpingState(delta):
	print("We are in the jumping state")
	velocity -= (JUMP_VELOCITY)*get_gravity() * delta
	
	  
	pass

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
		
	#print(Onreface)
	# Handle jump.
	#if Input.is_action_just_pressed("jump") and is_on_floor() and Onreface == true:
#		velocity.y = JUMP_VELOCITY
#		state_machine.travel("jump")
#		inair = true
#	elif Input.is_action_just_pressed("jump") and is_on_floor() and Onreface == false:
#		state_machine.travel("jumpleft")
#		inair = true

	

	
		
	if not is_on_floor():
		velocity += get_gravity() * delta
		currentstate = playerstate.fall
	elif is_on_floor() and Onreface == false:
		currentstate = playerstate.idle
	elif is_on_floor() and currentstate == playerstate.fall:
		currentstate = playerstate.idle
	else:
		currentstate = playerstate.idleleft
	
	if Input.is_action_pressed("left"):
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
		
	elif Input.is_action_pressed("right"):
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
	
	if Input.is_action_just_pressed("jump") and is_on_floor():
		
		jumpclock.start(2.4)
		if(Onreface == false):
			currentstate = playerstate.jump
			
		elif(Onreface == true):
			currentstate = playerstate.jumpleft
			
		
	if Input.is_action_just_pressed("enter"):
		currentstate = playerstate.attack
		# need to show differen attack determined if player is on the floor of not
		pass
	
	
		

	if(jumpclock.time_left > 0):
		JumpingState(delta)
	
	match currentstate:
		playerstate.idle:
			
			$Onreani.play("idle")
			
		playerstate.idleleft:
		
			$Onreani.play("idleleft")
		
		
		playerstate.walk:
			$Onreani.play("walk")
			#test.play("walk")
			$Onre.flip_h = false
		
		playerstate.walkleft:
			$Onreani.play("walk")
			$Onre.flip_h = true
			
		playerstate.attack:
			$Onreani.play("attack")
			
		playerstate.fall:
			$Onreani.play("fall")
		_:

			pass
				
	#print(currentstate)	
		
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
	if direction:
		velocity.x = direction * SPEED
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)
	
	#print(Onreface)
	print(jumpclock.time_left)	
		
	
	
	move_and_slide()
