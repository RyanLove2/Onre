extends CharacterBody2D


const SPEED = 150 #300
const JUMP_VELOCITY = -400.0
var Onreface
var  attacking 
var inair
func _onready():
	Onreface = false
	attacking = false
	inair = true
	
	

func _physics_process(delta):
	# Add the gravity.
	var state_machine = $AnimationTree["parameters/playback"]
	attacking = false
	if not is_on_floor():
	#	velocity += get_gravity() * delta
		pass
	
	
	
	
	# Handle jump.
	if Input.is_action_just_pressed("jump") and is_on_floor() and Onreface == true:
		velocity.y = JUMP_VELOCITY
		state_machine.travel("jump")
		inair = true
	elif Input.is_action_just_pressed("jump") and is_on_floor() and Onreface == false:
		state_machine.travel("jumpleft")
		inair = true
		
		
	
	
	if Input.is_action_pressed("left"):
		Onreface = false
		#attacking = false
		state_machine.travel("walkleft")
	elif Input.is_action_just_released("left"):
		state_machine.travel("idleleft")
		
		
	elif Input.is_action_pressed("right"):
		Onreface = true
		#attacking = false
		state_machine.travel("walk")
	elif Input.is_action_just_released("right"):
		state_machine.travel("idle")
	
		
	if Input.is_action_just_pressed("enter"):
		#attacking = true
		if Onreface == false:
			state_machine.travel("attackleft")
		else:
			state_machine.travel("attack")
		
	elif Input.is_action_just_released("enter") and Onreface == true:
		state_machine.travel("idle")
	elif Input.is_action_just_released("enter") and Onreface == false:
		state_machine.travel("idleleft")
		
	
		

		
	# Get the input direction and handle the movement/deceleration.
	# As good practice, you should replace UI actions with custom gameplay actions.
	var direction = Input.get_axis("left", "right")
	if direction:
		velocity.x = direction * SPEED
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)
		
		
	
		
	move_and_slide()
