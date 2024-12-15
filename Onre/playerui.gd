extends Control

@onready var change_wp = get_node("PanelContainer/Container/weapon_selection")
@onready var lifebar = get_node("PanelContainer/Container/playerportrait")
@onready var p = get_node("PanelContainer/Container/power")
var wp = load("res://Scripts/WeaponSelectionCode.gd")
var wp_obj = wp.new()

@onready var life = 0
@onready var ability = 0
@onready var manifest = 0
# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	#lifebar.frame = life
	
	if Input.is_action_just_pressed("select"):
		ability =	wp_obj.UiSelection(ability)
		change_wp.frame = ability
		
	if Input.is_action_just_pressed("power"):
		manifest = wp_obj.PowerSelection(manifest)
		p.frame = manifest
		
