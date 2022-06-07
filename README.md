<h3 align="center">CSCI 340 Project 1</h3>

  <p align="center">
    Alex Bailey & Janae Dorsey 
    <br />
    <br />
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

This project is a an assignment for CSCI 340: Operating Systems with Dr. Ralph Crosby. We had about 3 weeks to complete the project with a partner. The program is compiled and assembled by a makefile, which is run by typing the ```make all``` command in the terminal. The actual program can be run by by typing ```./project1``` in the terminal. Initially, we ran into an issue obtaining information for each process because we weren't sure how to insert the differnt PIDs into the **'fopen("proc/pid/stat", "r")'** statement to pull the info for each process. It was interesting to see that we had to scan the file for all of its contents. We also had some trouble printing out the raw information. We ran into segmentation faults a few times and we couldn't get the output to print in a tree format as instructed. 

We submitted 2 programs: project1.c and project1nonfunct.c. Project1 runs, but the information is not formatted in a tree. In project1nonfunct.c, we attempted to store the data in a linked list, however, we kept getting a segmentation fault using this method. 

<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* [Ubuntu](https://ubuntu.com/)
* [C](https://en.wikipedia.org/wiki/C_(programming_language))


<p align="right">(<a href="#top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

This project was a class assignment.

See the [open issues](https://github.com/baileyam99/Project-1-CSCI340/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#top">back to top</a>)</p>

## Contact Me

Contact me through the [Contact Me](https://alexbaileyresume.com/contact) section of my function resume site.

<p align="right">(<a href="#top">back to top</a>)</p>
