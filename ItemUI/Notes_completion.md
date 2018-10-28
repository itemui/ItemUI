Date: 16/08/2018
Check on data loaded from bin file displayed in UI

TODO: Decrease latency by checking whether a variable changed or not in a screen then only call the function

# Screens

- InputScreen1 - data correctly displayed--verification done

- Wind data - data correcly displayed, run button is working correctly

- Seismic data - Working fine at runtime. Data displayed correctly.

- Shell design - Data displayed correctly. Working fine at runtime.

- PWG - Data displayed correctly. Working fine at run time.

- Stiffener Elevation - Data displayed correctly. There are a couple of fields that I couldn't verify due to their absence from result file. Run time behaviour is fine.

- Stiffener Size - Data displayed correctly for design fields. `Run` is working fine.




# For checking design/run buttons, follow these instructions

1. Wind data - Try to change any variable on which `design wind velocity` depends and then click on the button. You will see the updated velocity.

2. Seismic Data - It contains `calculate Fa, Fv` button. In this case, if you update anything on which Fa, Fv depends then click on this button and the values of Fa and Fv will change in the respective fields. 

In this window, if you change any variable on which `Sd1` and `SDS` depends then the values of Sd1 and SDS will be changed automatically.

3. Shell design - As soon as we open this window, shell_details() function from console program is called which updates all the variables and populated the user defined variables in the grid.

- It window contains two buttons, `Add shell course` and `Design`.

`Add shell course` - whenever, you change `course width` or `corrosion allowance`, you must click this button. failure to do so will not update the variables and may result in unexpected behaviour.

`Design` - Using the user defined values, it calls `shell_details()` function at the backend and will populate the other columns.

4. Primary Wind Girder - It has a `run` button which should be run when any of the user inputs are changed. Calls the PWG_data() function from console and updates the values in the grid.

5. Stiffener Elevation - As soon as this window is opened, the `shell_Stfr_User_EL_Data()` is called. The grid contains a `user input field - user defined elevation`. Whenever you edit it, please click on the `RUN` button in the corresponding row. Currently, the `RUN` button above the grid doesn't do anything. I'm planning to use that in future.

6. Stiffener Size - Open this window. Edit the details you like and click the `Run` button. This will call the `Stiffener_Prop_User_Data` function from the console program. After that it will update the grid with new values.