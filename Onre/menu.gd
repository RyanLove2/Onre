extends Node2D



# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


func startButtonPressed():
	get_tree().change_scene_to_file("res://main_room.tscn") # subject tochange
	#get_tree().change_scene_to_file("res://Onre.tscn") 

func quitButtonPressed():
	self.get_tree().quit()

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass
