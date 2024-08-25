#blender
#Install in linux
```
sudo snap install blender --classic
blender
#Writing userprefs: "/home/abhinandan/.config/blender/4.2/config/userpref.blend" ok
```

test script<br>

```python

import bpy

#Ensure you're in Object Mode
if bpy.context.object and bpy.context.object.mode != 'OBJECT':
    bpy.ops.object.mode_set(mode='OBJECT')

#Clear existing objects
bpy.ops.object.select_all(action='SELECT')
bpy.ops.object.delete(use_global=False)

#Create the main body parts
def create_body_part(name, shape, location, dimensions):
    if shape == 'cube':
        bpy.ops.mesh.primitive_cube_add(size=1, location=location)
        body_part = bpy.context.object
        body_part.scale = dimensions
    elif shape == 'cylinder':
        bpy.ops.mesh.primitive_cylinder_add(radius=dimensions[0], depth=dimensions[1], location=location)
        body_part = bpy.context.object
        body_part.scale = (dimensions[0], dimensions[0], dimensions[1])  #X and Y for radius, Z for depth
    elif shape == 'sphere':
        bpy.ops.mesh.primitive_uv_sphere_add(radius=dimensions[0], location=location)
        body_part = bpy.context.object
        body_part.scale = (dimensions[0], dimensions[0], dimensions[0])
    
    body_part.name = name
    return body_part

#Create a detailed PUBG-like character body parts
torso = create_body_part("Torso", 'cube', (0, 0, 1), (1, 0.5, 1.5))
head = create_body_part("Head", 'sphere', (0, 0, 2.75), (0.4, 0.4, 0.4))
left_arm_upper = create_body_part("Left_Upper_Arm", 'cylinder', (-1.1, 0, 1.7), (0.15, 1))
left_arm_lower = create_body_part("Left_Lower_Arm", 'cylinder', (-1.5, 0, 1.2), (0.12, 0.9))
right_arm_upper = create_body_part("Right_Upper_Arm", 'cylinder', (1.1, 0, 1.7), (0.15, 1))
right_arm_lower = create_body_part("Right_Lower_Arm", 'cylinder', (1.5, 0, 1.2), (0.12, 0.9))
left_leg_upper = create_body_part("Left_Upper_Leg", 'cylinder', (-0.5, 0, 0.2), (0.2, 1.2))
left_leg_lower = create_body_part("Left_Lower_Leg", 'cylinder', (-0.5, 0, -0.7), (0.18, 1))
right_leg_upper = create_body_part("Right_Upper_Leg", 'cylinder', (0.5, 0, 0.2), (0.2, 1.2))
right_leg_lower = create_body_part("Right_Lower_Leg", 'cylinder', (0.5, 0, -0.7), (0.18, 1))

#Create an armature for rigging
bpy.ops.object.armature_add(location=(0, 0, 0))
armature = bpy.context.object
armature.name = "PUBG_Like_Character_Rig"

#Enter Edit Mode to add bones
bpy.ops.object.mode_set(mode='EDIT')

#Add bones to the armature
def add_bone(armature, name, head, tail):
    bone = armature.data.edit_bones.new(name)
    bone.head = head
    bone.tail = tail
    return bone

#Create bones for the rig
spine = add_bone(armature, "Spine", (0, 0, 0), (0, 0, 1.5))
neck = add_bone(armature, "Neck", (0, 0, 1.5), (0, 0, 2))
head_bone = add_bone(armature, "Head", (0, 0, 2), (0, 0, 2.75))
left_upper_arm_bone = add_bone(armature, "Left_Upper_Arm", (-0.5, 0, 1.5), (-1.1, 0, 1.5))
left_lower_arm_bone = add_bone(armature, "Left_Lower_Arm", (-1.1, 0, 1.5), (-1.5, 0, 1.2))
right_upper_arm_bone = add_bone(armature, "Right_Upper_Arm", (0.5, 0, 1.5), (1.1, 0, 1.5))
right_lower_arm_bone = add_bone(armature, "Right_Lower_Arm", (1.1, 0, 1.5), (1.5, 0, 1.2))
left_upper_leg_bone = add_bone(armature, "Left_Upper_Leg", (-0.5, 0, 0.5), (-0.5, 0, 0))
left_lower_leg_bone = add_bone(armature, "Left_Lower_Leg", (-0.5, 0, 0), (-0.5, 0, -0.7))
right_upper_leg_bone = add_bone(armature, "Right_Upper_Leg", (0.5, 0, 0.5), (0.5, 0, 0))
right_lower_leg_bone = add_bone(armature, "Right_Lower_Leg", (0.5, 0, 0), (0.5, 0, -0.7))

#Exit Edit Mode
bpy.ops.object.mode_set(mode='OBJECT')

#Parenting the body parts to the bones
def parent_to_bone(body_part, bone_name):
    #Select the body part
    body_part.select_set(True)
    #Set the armature as active
    bpy.context.view_layer.objects.active = armature
    #Set the parent to the bone
    bpy.ops.object.parent_set(type='BONE', keep_transform=True)
    body_part.parent_bone = bone_name
    body_part.parent_type = 'BONE'

#Parent the body parts to the respective bones
parent_to_bone(torso, "Spine")
parent_to_bone(head, "Head")
parent_to_bone(left_arm_upper, "Left_Upper_Arm")
parent_to_bone(left_arm_lower, "Left_Lower_Arm")
parent_to_bone(right_arm_upper, "Right_Upper_Arm")
parent_to_bone(right_arm_lower, "Right_Lower_Arm")
parent_to_bone(left_leg_upper, "Left_Upper_Leg")
parent_to_bone(left_leg_lower, "Left_Lower_Leg")
parent_to_bone(right_leg_upper, "Right_Upper_Leg")
parent_to_bone(right_leg_lower, "Right_Lower_Leg")

#Switch to Pose mode to manipulate the character
bpy.context.view_layer.objects.active = armature
bpy.ops.object.mode_set(mode='POSE')
```
#### PUBG Character Design:
```
print("PUBG-like character with moveable joints create successfully!")

```
