*1. NPC System*
Files: Npc.h, Npc.cpp

*2. Kinematics System*
Kinematic Behaviors (Velocity-Based)

  IDLE (SteeringBehaviorIDLE.h/.cpp): No movement
  SEEK (SteeringBehaviorKinematicSEEK.h/.cpp): Move toward a target position
  FLEE (SteeringBehaviorKinematicFLEE.h/.cpp): Move away from a target position
  WANDER (SteeringBehaviorKinematicWANDER.h): Random wandering with configurable strength and direction change intervals
  
Dynamic Behaviors (Force-Based)
  SEPARATION (SteeringBevahiorDynamicSEPARATION.h): Avoid crowding neighbors
  COHESION (SteeringBehaviorDynamicCOHESION.h): Move toward the center of mass of neighbors
  VELOCITY MATCHING (SteeringBehaviorDynamicVELOCITYMATCHING.h): Match velocity with nearby agents
  FLOCKING (SteeringBehaviorDynamicFLOCKING.h): Combined separation, cohesion, and velocity matching with weighted contributions

*3. Decision Tree System*
Files: DecisionTreeReasoner.h, NodeDT.h, DecisionNodeDT.h, BooleanNodeDT.h/.cpp, OptionNodeDT.h/.cpp

Tree-based decision making framework
Boolean decision nodes with true/false branches
Leaf nodes containing executable options
Runtime tree traversal and decision execution

*4. Knowledge System*
Files: Knowledge.h/.cpp, KnowledgePosition.h/.cpp, KnowledgeKinematicGroup.h/.cpp

Knowledge: Abstract base class for storing world information
KnowledgePosition: Stores position data (used for targets)
KnowledgeKinematicGroup: Manages groups of kinematic agents (used for flocking)

Boolean evaluation system for decision making
Connects knowledge to decision nodes
Computes boolean values for tree traversal
