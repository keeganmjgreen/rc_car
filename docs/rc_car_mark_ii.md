

# RC Car Mark II



## Power Electronics Design — Custom Unidirectional [Motor Driver](https://en.wikipedia.org/wiki/Motor_controller)

[~~Motor Soft Starter~~](https://en.wikipedia.org/wiki/Motor_soft_starter)



**NPN [bipolar junction transistor (BJT)](https://en.wikipedia.org/wiki/Bipolar_junction_transistor) — [common-emitter](https://en.wikipedia.org/wiki/Common_emitter) ~~amplifier~~ *switching device*:**



![](equation_1.svg)

![](equation_2.svg)

![](equation_3.svg)

------



<img src="assets/output-1.png" alt="Figure 1a: Modified from [1]." style="zoom:6.25%;" /> <img src="assets/output-2.png" alt="Figure 1b: Modified from [1]." style="zoom:6.25%;" />



Figure 1: Modified from [1].

------

![](assets/implies.svg) **[Darlington pair](https://en.wikipedia.org/wiki/Darlington_transistor):** input transistor (![](assets/Q_I.svg)), output transistor(s?)(TBD) (![](assets/Q_O.svg))  …

![](equation_4.svg)

![](equation_5.svg)

![](equation_6.svg)

![](equation_7.svg)

![](equation_8.svg)

![](equation_9.svg)



- **Which kind of switching device?**

  Medium-power NPN [bipolar junction transistor (BJT)](https://en.wikipedia.org/wiki/Bipolar_junction_transistor)’s on-hand.

  `PN2222A-D32`

- **Which circuit topology/configuration?**

  Overall: [common-emitter](https://en.wikipedia.org/wiki/Common_emitter) ~~amplifier~~ *switching device*.

  [Darlington pair](https://en.wikipedia.org/wiki/Darlington_transistor).

- **Which transistors? How many? How many stages? Which ‘region’ of operation?**

  Stage 1: 600-mA [or less] NPN’s (×1) in saturation. Alternative: motor driver board.
  Stage 2: 600-mA NPN’s (×12) pushing saturation.

- **What current-limiting resistance? Which resistors? How many?**

  $ R_B \lessapprox 6060 \ \Omega \, \longrightarrow 5500 \ \Omega = \textsf{four on-hand} \ 22 \mathrm{k} \textsf{'s in parallel} $.



**Failure analysis:**

- Factor 1: One-at-a-time activation and subsequent burnout of all stage 2 BJTs.

- Factor 2: Nonzero load (non-frictional) torque (‘freewheeling’).

  $ \displaystyle \textsf{starting inrush current} \begin{aligned}[t] & \longrightarrow \textsf{motor starts} \\ & \longrightarrow \textsf{gears backlash against nonzero torque} \\ & \longrightarrow \textsf{motor slows down} \\ & \longrightarrow \textsf{sustained inrush current} \\ & \longrightarrow \textsf{BJTs burn out} \\ & \longrightarrow \textsf{current stops} \\ & \longrightarrow \textsf{motor stops}  \end{aligned} $

$ \displaystyle R_B < R_{\, \textsf{coil}} \cdot \beta \, \cdot \frac{V_{BB} - V_{\, \mathrm{D}, \, \textsf{on}}}{ V_{CC} - V_{\, \mathrm{D}, \, \textsf{on}}} = 225 \ \Omega \cdot 100 \cdot \frac{5.0 \ \mathrm{V} - 0.7 \ \mathrm{V}}{7.4 \ \mathrm{V} - 0.7 \ \mathrm{V}} \approx 14.4 \ \mathrm{k} \Omega \implies R_B = \boxed{\, ? \,} $

$ \displaystyle i_B \approx \frac{5.0 \ \mathrm{V} - 0.7 \ \mathrm{V}}{?} \approx \; ?? \ll 40 \ \mathrm{mA} \ \textsf{max per I/O Pin(s?)} $

$ v_{\, \textsf{coil}} \, \left( \, = v_{\, \textsf{coil}, \, \textsf{max}} \right) = V_{CC} - v_{CE, \, \textsf{sat}} \approx 7.4 \ \mathrm{V} - 0.7 \ \mathrm{V} = \boxed{\textsf{only} \ 6.7 \ \mathrm{V} \left( < 7.4 \ \mathrm{V} \right) \ \textsf{across relay coil}} $

$ \displaystyle i_a \! \left( t = 0 \right) = v_a / R_a = \boxed{7.4 \ \mathrm{V}} \; / \left( 1 \ \Omega \right) = \boxed{7.4 \ \mathrm{A} \ \textsf{starting current draw}} \quad \textsf{(!)} $



## [Powertrain](https://en.wikipedia.org/wiki/Powertrain) Design



**[Brushed DC electric motor](https://en.wikipedia.org/wiki/Brushed_DC_electric_motor):**

- Model airplane propeller drive.

- No datasheet or specifications within reach.

  ```
  51287V2
  610223-1(B)
  ```



### [Drivetrain](https://en.wikipedia.org/wiki/Drivetrain) Design



$ \displaystyle R = \frac{\mathrm{rpm}_A}{\mathrm{rpm}_B} \, \left( = \frac{\omega_A}{\omega_B} = \frac{r_A}{r_B} \right) = \frac{N_A}{N_B} = \frac{24 \ \textsf{teeth}}{\phantom{0}8 \ \textsf{teeth}} = \boxed{\, 3 : 1 \,} \implies R_\textsf{tot.} = \prod_{i=1}^{n} R_i = \left( R \right) ^ n = \left( 3 \right) ^ 4 = \boxed{\, 81 : 1 \,} $



**Alternatives:**

- +1 three-to-one’s $ \implies $ too slow
- −1 three-to-one’s $ \implies $ too fast
- +1 two-to-one’s $ \implies $ not enough chassis space
- −1 three-to-one’s + 1 two-to-one $ \implies $ not enough chassis space — ?
- −2 three-to-one’s + 1 two-to-one $ \implies $ too fast



## [Chassis](https://en.wikipedia.org/wiki/Chassis) Design



LEGO Technic

| Components                                             | Dimensions (Approx.) |
| ------------------------------------------------------ | -------------------- |
| [Frame](https://en.wikipedia.org/wiki/Vehicle_frame)   | 12 cm × 12 cm        |
| [Axle Track](https://en.wikipedia.org/wiki/Axle_track) | 20 cm                |
| [Wheelbase](https://en.wikipedia.org/wiki/Wheelbase)   |                      |
| Length                                                 | 17 cm                |
