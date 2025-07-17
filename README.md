# 🧪 Unreal Prototypes

🎮 A collection of small prototypes made with **Unreal Engine 5**, where I experiment with different mechanics by trying to recreate them through reverse engineering.

---

## 🎥 Prototype Showcase

<table>
  <tr>
    <td>
      <strong>🛡️ Parry</strong><br/>
      This Unreal Engine prototype demonstrates a parry mechanic where, during enemy attacks,  
      a short parry window allows the player to stun the enemy with precise timing.  
      These parry windows are driven by animation events, ensuring synchronization with enemy attack motions.<br/><br/>
      <video src="https://github.com/user-attachments/assets/889d2b80-e2a5-4932-a583-e0141174c5f4" width="320" controls></video>
    </td>
    <td>
      <strong>✈️ Flight Simulator</strong><br/>
      This Unreal prototype simulates the movement of an airplane using basic interactive controls.  
      It features two buttons to increase and decrease speed, allowing users to adjust velocity dynamically.  
      The prototype also supports rotation via the WASD keys: pressing these keys modifies the airplane’s pitch and roll, enabling realistic flight dynamics.<br/><br/>
      <video src="https://github.com/user-attachments/assets/e4da5ef0-56a8-4909-a587-ad1e1c3e5b11" width="320" controls></video>
    </td>
  </tr>
  <tr>
    <td>
      <strong>🎯 Aim Assist</strong><br/>
      Aim assist mechanic in Unreal that helps players aim more accurately when looking near an enemy target.  
      It uses a collision sphere around enemies to detect proximity then leverages the dot product to identify the best target in front of the player.  
      Finally, the system rotates the camera on the Y and Z axes to align with the target’s center.<br/><br/>
      <video src="https://github.com/user-attachments/assets/b9996905-62aa-4fbc-91d1-b14b157cfb2b" width="320" controls></video>
    </td>
    <td>
      <strong>🌫️ Fog Of War</strong><br/>
      In this Unreal prototype, I implemented a dynamic fog of war system that hides specific actors in the environment.  
      These actors remain invisible until the player either gets within a certain distance or brings them into their forward-facing field of view.  
      When revealed, the actors smoothly fade in, creating a subtle and immersive transition effect.<br/><br/>
      <video src="https://github.com/user-attachments/assets/290b9678-7e5c-423c-be96-35967be9bd44" width="320" controls></video>
    </td>
  </tr>
  <tr>
    <td>
      <strong>⏳ Sands Of Time</strong><br/>
      In this Unreal prototype, this mechanic allows the player to rewind time similarly to *Prince of Persia: The Sands of Time*.  
      By holding down a specific key, the character smoothly retraces their recent movements, stepping backward through their previous positions.  
      The system records the player's transforms over time and plays them back in reverse while the key is held, creating a fluid and responsive rewind effect.<br/><br/>
      <video src="https://github.com/user-attachments/assets/2fdeaf4c-096d-4175-a2e8-ccbd208a7e00" width="320" controls></video>
    </td>
    <td>
      <strong>🌀 Portals</strong><br/>
      A *Portal*-like mechanic in Unreal that lets you teleport from one point to another.  
      The portals show the other portal's view based on the direction and rotation of the player, creating a seamless visual transition.<br/><br/>
      <video src="https://github.com/user-attachments/assets/9d1f1108-6544-4924-82aa-51d32c8c6465" width="320" controls></video>
    </td>
  </tr>
  <tr>
    <td>
      <strong>🧲 Push & Pull Force</strong><br/>
      A *Star Wars*-inspired push & pull mechanic in Unreal that lets you control the movement of selected objects by attracting or pushing them away.  
      The attraction mechanic uses a spherecast in the forward vector; if it intersects an object, it starts pulling it toward you.  
      The object follows the camera point of view until you push it in the direction you're looking at.<br/><br/>
      <video src="https://github.com/user-attachments/assets/f73bd8c0-341c-4608-be64-859a61768cc1" width="320" controls></video>
    </td>
    <td>
      <strong>🚢 Floating Ship</strong><br/>
      A floating ship simulation in Unreal where a trigger placed above the water checks which objects are inside it  
      and applies a force to them based on their mass, volume, and the density of the water — simulating buoyancy physics.<br/><br/>
      <video src="https://github.com/user-attachments/assets/7a140244-7126-46f9-a0e8-146495e0d7e7" width="320" controls></video>
    </td>
  </tr>
</table>
