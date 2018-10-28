# ItemUI

Let's start:

## Building project on your machine
1. Open up the codeblocks and create an empty project named `ItemUI` in your favorite directory.

2. Copy the files from this repo in your directory except xml files(with extension .wxs) which will be there in `wxsmith/` directory.

3. Now, at the top of codeblocks, you will see wxsmith. Click on it and then `Add wxDialog`. Now, you need to add all the UI screens one by one which are: `ItemUIMain`, `InputScreensDlg`, `StiffenerSelection`, `UTSDlg`(These are the names of the classes). when you'll click on add finally, it creates 3 files for you automatically, classname.h, classname.cpp and wxsmith/classname.wxs. As you already have the corresponding .cpp and .h files, so codeblocks will ask you whether to replace files or not. You need to keep my version of these files. So, select accordingly. Do this for all classes. `ItemUIMain` will already be there. So, no need to add dialog for this one.

4. Now, you have my version of .cpp and .h files. This is the time to copy `.wxs` files. Copy them. Now go to codeblocks and then you will need to right click on wxs files and then select `Reparse this file` to update the UI. Hope it's clear.

5. Initially, you may get the errors in the parts where I have implemented pdf functionality. Please comment those out for now.

Guess, it's not a lot of information and you will be able to build it successfully.

## Getting familiar with the work flow

First thing, there are some design functions defined in `Tank.cpp` by Sir himself, which are run to perform the calculations. Now, to keep UI stuff which we developed and design functions separate and so that Sir can independently revise his part of code, we didn't explicitly copy these functions with UI codes.

So, first thing that I suggest you to do is running this Tank.cpp file. Create a separate project in codeblocks or whatever way you want, compile(copy ItemHeaders.h from ItemUI/include directory first) and run this file. Change the name of function `maintest()` to `main()`. Should compile successfully XD. Get familiar with what's going on. As soon as you run it, it'll ask you to write a `file_name`. Enter any name and it will ask you to enter a lot of values enter them as you wish. When everything is done, it'll create 2 files, `file_namedata.bin` and `file_nameResult.txt`. Cool? `Data` and `Result` will be appended to the `file_name`.

This bin file contains a struct which is defined in ItemHeaders.h(InputData). Just take a look at all the data members. And you can't store strings in this struct. Doing so will make it a non-POD(Google about it).

Now, again run this file, type the same name as you did previously and see what happens :joy. Go through main().

Great!!

So, corresponding to each of the function in main(), we have different windows in InputScreens UI.

Now, as we leave a window or enter one, we need to run these design functions as per the requirements. Look at the function `OnNotebookInputScreen_1PageChanged()`. Based on various options, a different set of function is called.

See, there are two functions `ReadVariables()` and `PopulateVariables()`. See `main()` in `Tank.cpp` and you will figure out hopefully why these are needed. In case, you don't, ping me. These were written by Sir for his `console program`. Sir differentiates our stuff with his by referring this term `console`. So, only `tank.cpp` means console and the rest of stuff with it makes our UI. Cool? XD.

You must have known by now the two modes for which Sir wrote `Tank.cpp`: `new file` and `existing one`. So, we leveraged the existing mode functionality to solve our purpose. What we do is get the values of parameters from the user from various UI windows and then store them in a `struct`(the same from ItemHeaders.h). Now, we call this function ReadVaribles() from UI(from InputScreensDlg.cpp) part(obviously when required) and this lets the tank.cpp know about the values of the required variables that user entered. Now, various functions are called and this way after some calculations, we get some new values for some variables.

Now, how do we let the user know what went on at the backend?? Here comes `PopulateVariables()` in picture. We call this function making the UI part know the updated values. Now, we just display them in the UI.

*Now, let's focus on `InputScreensDlg.cpp`*, the most important file for the UI. It has almost everything. See there are some functions with the name starting with `set****()*. These are used for setting control states/values for each window plus some validations. Look at teh header file for function declarations. You will find them easily there.
```
        void SetupValidators();
        void SetInitialControlValues();
        void SetInitialControlStates();
```

Maze karr. Ping me for doubts.
