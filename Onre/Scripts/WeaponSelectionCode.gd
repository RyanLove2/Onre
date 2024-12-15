



func WeaponSelection(weapon_selection: int):

		if weapon_selection >= 3:
			weapon_selection=0
		else:
			weapon_selection +=1 
		
		return weapon_selection


func UiSelection(weapon_selection: int):

		if weapon_selection >= 3:
			weapon_selection=0
		else:
			weapon_selection +=1 
		
		return weapon_selection
		
	
func PowerSelection(power: int):
	
	if power >=4:
		power = 0
	else:
		power+=1
	return power
	
		
