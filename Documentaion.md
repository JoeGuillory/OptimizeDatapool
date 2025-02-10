# Documentation
This is Documentation for the [List](#list), [Map](#map), And [ObjectPool](#ObjectPool) classes
## List
It is a Templeted Class that will be able to add and remove things really quick

### Functions

| List      | Functions                                                           |
|-----------|---------------------------------------------------------------------|
| pushFront | This will set the new object to be in the front of the list         |
| pushBack  | This will set the new object to be in the back of the list          |
| popFront  | This will Remove the first thing in the list                        |
| popBack   | This will Remove the Last Thing in the list                         |
| insert    | Insert a object in the list into a certain place                    |
| remove    | This will remove all instances of the object in the list            |
| first     | This will return the value of the First thing in the list           |
| last      | This will return the value of the Last thing in the list            |
| begin     | This will return a iterator that start at the beginning of the list |
| end       | This will return a iterator that start at the end of the list       |
| destroy   | This will remove everything in the list                             |
| getLength | This will return the length of the list                             |

### Operators
| Operators |                                            |
|-----------|--------------------------------------------|
| =         | Make the current list equal to another     |
| ==        | Checks if one list is equal to another     |
| !=        | Checks if one list in not equal to another |

## Map
This a container that stores Pairs. The Pairs store two different types of variable. This container will find the right pair and return the correct value from the pair.

### Functions
| Map    |                                                            |
|--------|------------------------------------------------------------|
| Insert | Insert two different types and add it to the map           |
| Insert | Inserts a Pair into the map                                |
| Remove | Insert a key to remove from the map                        |
| Get    | Returns the value from the key inputted into the function  |


##ObjectPool
This is a data type that will store a bunch of object. It will then give you inactive object and take back active objects.

### Functions

| Object Pool   |                                                     |
|---------------|-----------------------------------------------------|
| CountActive   | Returns the amount of active objects                |
| CountInactive | Returns the amount of inactive objects              |
| CountAll      | Returns the amount of objects in the pool           |
| Clear         | Empties the object pool                             |
| Get           | Returns a inactive object                           |
| GetActive     | Returns the list of Active objects                  |
| Release       | Puts the Active object back into the inactive pool  |




















