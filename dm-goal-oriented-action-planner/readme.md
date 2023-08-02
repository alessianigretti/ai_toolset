# Goal-Oriented Action Planning
## The Theory
### What is it?
Goal-Oriented Action Planning (GOAP) is an AI technique commonly used in video game development and robotics to enable agents to achieve specific goals efficiently.
GOAP is based on the idea of representing actions and their effects in a formalized manner, allowing the AI agent to construct plans or sequences of actions to reach desired objectives.
By considering the current state of the environment, the agent's capabilities, and the desired goal, GOAP employs heuristic search algorithms to find the optimal plan of actions to achieve the goal.
### When should it be used?
GOAP is best suited for scenarios where AI agents need to adapt and plan their actions dynamically to achieve specific objectives in a complex and changing environment.
It excels in situations where agents have multiple possible actions and goals and need to make intelligent decisions based on their surroundings.
GOAP is commonly used in video games for character AI, allowing NPCs to exhibit goal-driven and strategic behaviors.
### When should it not be used?
GOAP might not be the most appropriate approach for simple or straightforward decision-making tasks where the complexity of representing actions and their effects outweighs the benefits.
If the AI agent has a limited set of actions or the environment is relatively static, other simpler techniques like rule-based systems or Finite State Machines could be more suitable.
### What are the common pitfalls of this approach?
Some common pitfalls of using GOAP include:
* Representation Complexity: The process of formalizing actions and their effects can become intricate, particularly in complex environments with numerous variables and interactions.
* Costly Planning: Finding an optimal plan using heuristic search algorithms can be computationally expensive, especially in large and dynamic environments, leading to potential performance issues.
* Goal Clashes: When multiple goals compete for priority, the AI agent may struggle to handle conflicting objectives effectively, leading to suboptimal or erratic behavior.
* Limited Real-Time Adaptation: GOAP plans are typically computed offline or at specific intervals, which can limit the agent's ability to adapt rapidly to rapidly changing situations.
## The Practice
### Sample Project
