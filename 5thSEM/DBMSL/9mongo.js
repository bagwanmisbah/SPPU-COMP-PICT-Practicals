use library

db.createCollection("books")

db.posts.insertOne(
    {
        title: "Alias Grace",
        author : "Margaret Atwood",
        year: "1996"
    }
)

db.posts.insertMany(
    [
        {
            title: "Harry Potter and the Philosopher's Stone",
            author : "J.K Rowling",
            year: "1997"    
        },
        {
            title: "Harry Potter and the Chamber of Secrets",
            author : "J.K Rowling",
            year: "1998"
            
        },
        {
            title: "Harry Potter and the Prisoner of Azkaban",
            author : "J.K Rowling",
            year: "1998"
            
        },
        
    ]
)
// db.posts.find({year:"1998"})


db.posts.find({}, { title: 1,_id:0})

db.posts.find({title:"Harry Potter and the Prisoner of Azkaban"})
//setting the year to its actual publication in 1999

db.posts.updateOne(
    {title:"Harry Potter and the Prisoner of Azkaban"},
     {$set:{year:"1999"}
    }
)
db.posts.find({title:"Harry Potter and the Prisoner of Azkaban"})































