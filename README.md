**Project Background:**

DNA, the carrier of genetic information in living things, has been used in criminal justice for
decades. But how, exactly, does DNA profiling work? Given a sequence of DNA, how can
forensic investigators identify to whom it belongs?
Well, DNA is really just a sequence of molecules called nucleotides, arranged into a particular
shape (a double helix). Each nucleotide of DNA contains one of four different bases: adenine
(A), cytosine (C), guanine (G), or thymine (T). Every human cell has billions of these
nucleotides arranged in sequence. Some portions of this sequence (i.e. genome) are the same, or
at least very similar, across almost all humans, but other portions of the sequence have a higher
genetic diversity and thus vary more across the population.

One place where DNA tends to have high genetic diversity is in Short Tandem Repeats (STRs).
An STR is a short sequence of DNA bases that tends to be repeated back-to-back numerous
times at specific locations in DNA. The number of times any particular STR repeats varies a lot
among different people. In the DNA samples below, for example, Alice has the
STR AGAT repeated four times in her DNA, while Bob has the same STR repeated five times.
![image](https://github.com/FenixVu442/DNA-Profiling-CS251-SP22/assets/104748038/bebe6f13-0243-4c01-a772-1fd181de68b4)
Using multiple STRs, rather than just one, can improve the accuracy of DNA profiling. If the
probability that two people have the same number of repeats for a single STR is 5%, and the
analyst looks at 10 different STRs, then the probability that two DNA samples match purely by
chance is about 1 in 1 quadrillion (assuming all STRs are independent of each other). So if two
DNA samples match in the number of repeats for each of the STRs, the analyst can be pretty
confident they came from the same person. CODIS, The FBI's DNA database, uses 20 different
STRs as part of its DNA profiling process. More on this later.

Ultimately, you are going to write a DNA profiling app. The app will be able to take a dna
strand and determine who the DNA belongs to (using a provided database). There are lots of
ways you could write an app like this, but for this project you will be required to solve it using
only the provided ourvector class.

**Project Summary:**

You are going to write an app that is able to build DNA strands using the provided ourvector
implementation and then determine who the DNA matches to in a database. The app will have a
menu, which is how the user communicates with your program. It is really important that write
your code in a module way and test as you go. The menu is designed specifically to encourage
this type of code develop. Let’s look at a sample input/output of the app (red text is user input,
everything else is output).

![image](https://github.com/FenixVu442/DNA-Profiling-CS251-SP22/assets/104748038/15ef39a3-538c-4168-bf09-6bd38a2edb5a)

