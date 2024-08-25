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

to move bones follow below steps :
```
Enter Pose Mode:
Press Ctrl + Tab and choose "Object/Pose Mode"
Select a Bone:
In Object Mode, left-click on a bone to select it.
If you want to select multiple bones, hold down Shift and left-click on each additional bone.
 Move the Bone:
press G to activate the move tool.
Rotate the Bone:
Press R to rotate the bone around the current pivot point.

set the pose :

Press Alt + Z or toggle X-Ray mode to view skeletal mode
```
```python
print("PUBG-like character with moveable joints create successfully!")

Creating a character model for a game like PUBG is a complex and multifaceted task that involves several advanced steps, including modeling, texturing, rigging, animation, and integration into a game engine like Unreal Engine. This process usually requires a deep understanding of 3D modeling software like Blender, as well as game development pipelines.

Here's an overview of the entire process:
Modeling the Character:

Create a High-Poly Model: Sculpt or model a detailed high-poly character in Blender. This involves creating the basic human anatomy, adding clothing, gear, and other details.
Retopology: Simplify the model to create a low-poly version suitable for games, maintaining the shape and detail as much as possible.
UV Unwrapping: Unwrap the model to create a 2D representation that can be textured.
Texturing the Model:

Bake Maps: Bake normal maps, ambient occlusion maps, and other necessary maps from the high-poly model to the low-poly model.
Texture Painting: Use software like Substance Painter or Blender to paint the character's textures, including skin, clothing, and gear.
Rigging the Character:

Create an Armature: Set up a skeleton (armature) with bones that will control the character's movements.
Weight Painting: Assign vertices to bones, allowing the mesh to deform correctly when the bones are moved.
Add IK/FK Controls: Implement inverse kinematics (IK) and forward kinematics (FK) for easier animation control.
Animating the Character:

Create Animations: Animate the character for various actions like running, shooting, and idle poses.
Export Animations: Export these animations in a format compatible with your game engine (e.g., FBX for Unreal Engine).
Integration into a Game Engine:

Import the Model: Import the rigged and animated character into Unreal Engine or another game engine.
Set Up Character Blueprints: In Unreal Engine, set up character blueprints, attach animations, and implement character controls.
Programming & Game Integration:

Implement in the Game: Program how the character interacts with the game world, including combat mechanics, physics interactions, and more.
Optimize: Ensure the character performs well in the game, adjusting LODs (Level of Detail) and optimizing textures and shaders.
Detailed Step-by-Step Guide:
1. Creating a High-Poly Model in Blender
Start by creating a detailed character model. You can begin with basic human anatomy using reference images.

Sculpting: Use Blender’s Sculpt Mode to create the details of the body, face, and clothing.
Modeling Gear: Use hard surface modeling techniques to create weapons, armor, and other gear.
2. Retopology and UV Unwrapping
After creating the high-poly model:

Retopology: Simplify the mesh to create a game-ready low-poly version. Use Blender’s retopology tools or manual modeling techniques.
UV Unwrapping: Unwrap the mesh to lay out the 2D UVs for texturing.
3. Texturing the Model
Use Substance Painter or Blender’s texture painting tools to add details:

Bake Normal Maps: Bake the high-poly details onto the low-poly model.
Texture Painting: Create albedo (color), roughness, metallic, and normal maps.
4. Rigging the Character
Create Armature: Set up the skeleton in Blender, making sure each bone corresponds to the body parts.
Weight Painting: Assign the mesh vertices to the appropriate bones.
IK/FK Controls: Implement controls for easy animation.
5. Animating the Character
Create Animations: Use Blender’s animation tools to create actions such as walking, running, and shooting.
Action Editor: Manage different animations within Blender.
6. Exporting to Unreal Engine
Export as FBX: Export the rigged and animated model in FBX format, ensuring all animations and rigging data are included.
Import into Unreal: Import the character into Unreal Engine, setting up the skeleton, physics assets, and character blueprints.
7. Integrating with the Game
Set Up Blueprints: Use Unreal’s Blueprint system to manage the character’s logic, interactions, and behavior in the game.
Optimize for Performance: Adjust the level of detail, optimize textures, and ensure the character runs smoothly in the game environment.
Resources to Learn:
Blender Tutorials: Many YouTube channels and websites offer in-depth tutorials on Blender modeling, texturing, and rigging.
Substance Painter: Tutorials on texturing, especially for game assets.
Unreal Engine Documentation: Guides on importing characters and setting up animations.
Game Development Courses: Consider taking online courses focused on game character design and animation.
Advanced Tools and Techniques:
Auto-Rigging: Use tools like Rigify in Blender or Auto-Rig Pro to speed up the rigging process.
Physics Simulation: Implement cloth and hair physics in Blender before exporting to Unreal.
LOD (Level of Detail): Create multiple versions of the model with decreasing detail for optimization in the game engine.
Conclusion:
Creating a character for a game like PUBG requires not only 3D modeling skills but also a deep understanding of the game development pipeline. While the steps provided here give an overview, mastering each part (modeling, texturing, rigging, animating, and integration) will take time and practice.
```
