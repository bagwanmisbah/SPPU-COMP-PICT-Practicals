db.orders.insertMany([
{
	"product":"plant",
	"price":21,
	"customer":"misbah"
},
{
	"product":"plant",
	"price":21,
	"customer":"riya"
},
{
	"product":"brush",
	"price":150,
	"customer":"anu"
},
{
	"product":"brush",
	"price":150,
	"customer":"anu"
},
{
	"product":"book",
	"price":20,
	"customer":"mansi"
},
{
	"product":"book",
	"price":20,
	"customer":"aryan"
}
]);

//1 FINDING OUT HOW MANY BOOKS WERE SOLD USING AGG FUNCTIONS MATCH AND GROUP
db.orders.aggregate([
    {
        $match: { product: 'book' }
    },
    {
        $group: {
            _id: "$product",
            totalQty: { $sum: 1 }
        }
    }
]);

//2. FINDING LIST OF ALL PRODUCTS SOLD USING GROUP
db.orders.aggregate([
    {
        $group: {
            _id: "$product"
        }
    }
]);
//3. FINDING TOTAL AMOUNT OF MONEY SPENT BY EACH CUSTOMER
db.orders.aggregate([
    {
        $group: {
            _id: "$customer",
            totalSpending: { $sum: "$price" }
        }
    }
])
//4. FIND PRODUCT WITH LEAST EARNINGS 
db.orders.aggregate([
    {
        $group: {
            _id: "$product",
            earnings: { $sum: "$price" }
        }
    },
    {
        $sort: {
            price: -1
        }
    },
    {
        $limit: 1
    }
])
// 6.FIND OUT HOW MUCH MONEY WAS SPENT ON BRUSHES AND BOOKS

db.orders.aggregate([
    {
        $match: { product: { $in: ['brush', 'book'] } }
    },
    {
        $group: {
            _id: "$customer",
            spending: { $sum: "$price" }
        }
    }
])

// 7.FIND OUT CUSTOMER WHO GAVE HIGHEST BUSINESS TO PLANTS 
db.orders.aggregate([
    {
        $match: { product: 'plant' }
    },
    {
        $group: {
            _id: "$customer",
            business: { $sum: "$price" }
        }
    },
    {
        $sort: { business: -1 }
    },
    {
        $limit: 1
    }
])





db.orders.insertOne({
"product":"plant"
})


db.orders.updateOne(
  { name: "misbah" },  
  { $push: { reviews: "Great plant!" } }  
);

SINGLE INDEX 
db.orders.createIndex({ "customer": 1 });

db.orders.createIndex({ "product": 1, "price": 1 });


db.flowers.insertMany([
  {
    "object_id": ObjectId(),
    "name": "Rose",
    "color": "Red",
    "price": 100,
  },
  {
    "object_id": ObjectId(),
    "name": "Tulip",
    "color": "Yellow",
    "price": 120,

  }
]);

------------------------------------------------------------------------------------------------------------------------------------------------------------------
[TE@fedora ~]$ mongo 10.10.12.248/te31455_db -u te31455 -p te31455
MongoDB shell version v4.4.4
connecting to: mongodb://10.10.12.248:27017/te31455_db?compressors=disabled&gssapiServiceName=mongodb
Implicit session: session { "id" : UUID("95175e9c-a09f-4f9d-ab7b-cdd76ab6fbca") }
MongoDB server version: 4.2.13
WARNING: shell and server versions do not match
---
The server generated these startup warnings when booting: 
2024-10-15T15:34:38.994+0530 I  STORAGE  [initandlisten] 
2024-10-15T15:34:38.994+0530 I  STORAGE  [initandlisten] ** WARNING: Using the XFS filesystem is strongly recommended with the WiredTiger storage engine
2024-10-15T15:34:38.994+0530 I  STORAGE  [initandlisten] **          See http://dochub.mongodb.org/core/prodnotes-filesystem
2024-10-15T15:34:43.427+0530 I  CONTROL  [initandlisten] 
2024-10-15T15:34:43.427+0530 I  CONTROL  [initandlisten] ** WARNING: Access control is not enabled for the database.
2024-10-15T15:34:43.427+0530 I  CONTROL  [initandlisten] **          Read and write access to data and configuration is unrestricted.
2024-10-15T15:34:43.427+0530 I  CONTROL  [initandlisten] 
---
> use te31455_db
switched to db te31455_db
> db.createCollection("orders");
{ "ok" : 1 }
> db.orders.insertOne({"product":"plant","price":21,"customer":"m"});
{
	"acknowledged" : true,
	"insertedId" : ObjectId("67108d0ed07853b2bbea91ba")
}
> db.orders.insertOne({"product":"plant","price":21,"customer":"misbah"});
{
	"acknowledged" : true,
	"insertedId" : ObjectId("67108d1bd07853b2bbea91bb")
}
> db.orders.insertMany([
... {
... "product":"plant",
... "price":21,
... "customer":"misbah"
... },
... {
... "product":"plant",
... "price":21,
... "customer":"riya"
... },
... {
... "product":"brush",
... "price":150,
... "customer":"anu"
... },
... {
... "product":"brush",
... "price":150,
... "customer":"anu"
... },
... {
... "product":"book",
... "price":20,
... "customer":"mansi"
... },
... {
... "product":"book",
... "price":20,
... "customer":"aryan"
... }
... ]);
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("67108d29d07853b2bbea91bc"),
		ObjectId("67108d29d07853b2bbea91bd"),
		ObjectId("67108d29d07853b2bbea91be"),
		ObjectId("67108d29d07853b2bbea91bf"),
		ObjectId("67108d29d07853b2bbea91c0"),
		ObjectId("67108d29d07853b2bbea91c1")
	]
}
> db.orders.aggregate([
...     {
...         $match: { product: 'book' }
...     },
...     {
...         $group: {
...             _id: "$product",
...             totalQty: { $sum: 1 }
...         }
...     }
... ]);
{ "_id" : "book", "totalQty" : 2 }
> //1 FINDING OUT HOW MANY BOOKS WERE SOLD
> db.orders.aggregate([
...     {
...         $match: { product: 'book' }
...     },
...     {
...         $group: {
...             _id: "$product",
...             totalQty: { $sum: 1 }
...         }
...     }
... ]);
{ "_id" : "book", "totalQty" : 2 }
> //1 FINDING OUT HOW MANY BOOKS WERE SOLD USING AGG FUNCTIONS MATCH AND GROUP
> db.orders.aggregate([
...     {
...         $match: { product: 'book' }
...     },
...     {
...         $group: {
...             _id: "$product",
...             totalQty: { $sum: 1 }
...         }
...     }
... ]);
{ "_id" : "book", "totalQty" : 2 }
> //2. FINDING LIST OF ALL PRODUCTS SOLD USING GROUP
> db.orders.aggregate([
...     {
...         $group: {
...             _id: "$product"
...         }
...     }
... ]);
{ "_id" : "plant" }
{ "_id" : "brush" }
{ "_id" : "book" }
> //3. FINDING TOTAL AMOUNT OF MONEY SPENT BY EACH CUSTOMER
> db.orders.aggregate([
...     {
...         $group: {
...             _id: "$customer",
...             totalSpending: { $sum: "$price" }
...         }
...     }
... ])
{ "_id" : "misbah", "totalSpending" : 42 }
{ "_id" : "aryan", "totalSpending" : 20 }
{ "_id" : "riya", "totalSpending" : 21 }
{ "_id" : "mansi", "totalSpending" : 20 }
{ "_id" : "anu", "totalSpending" : 300 }
{ "_id" : "m", "totalSpending" : 21 }
> //4. FIND PRODUCT WITH LEAST EARNINGS 
> db.orders.aggregate([
...     {
...         $group: {
...             _id: "$product",
...             earnings: { $sum: "$price" }
...         }
...     },
...     {
...         $sort: {
...             price: -1
...         }
...     },
...     {
...         $limit: 1
...     }
... ])
{ "_id" : "plant", "earnings" : 84 }
> // 6.FIND OUT HOW MUCH MONEY WAS SPENT ON BRUSHES AND BOOKS
> 
> db.orders.aggregate([
...     {
...         $match: { product: { $in: ['brush', 'book'] } }
...     },
...     {
...         $group: {
...             _id: "$customer",
...             spending: { $sum: "$price" }
...         }
...     }
... ])
{ "_id" : "aryan", "spending" : 20 }
{ "_id" : "anu", "spending" : 300 }
{ "_id" : "mansi", "spending" : 20 }
> // 7.FIND OUT CUSTOMER WHO GAVE HIGHEST BUSINESS TO PLANTS 
> db.orders.aggregate([
...     {
...         $match: { product: 'plant' }
...     },
...     {
...         $group: {
...             _id: "$customer",
...             business: { $sum: "$price" }
...         }
...     },
...     {
...         $sort: { business: -1 }
...     },
...     {
...         $limit: 1
...     }
... ])
{ "_id" : "misbah", "business" : 42 }
> 
> db.customers.updateOne(
...   { name: "misbah" },  // Find the customer by name
...   { $push: { reviews: "Great plant!" } }  // Add a simple review
... );
{ "acknowledged" : true, "matchedCount" : 0, "modifiedCount" : 0 }
> {
...   "_id": ObjectId("..."),
...   "name": "misbah",
...   "reviews": [
...     "Great plant!"
...   ]
... }
uncaught exception: SyntaxError: unexpected token: ':' :
@(shell):2:7
> db.orders.updateOne(
...   { name: "misbah" },  
...   { $push: { reviews: "Great plant!" } }  
... );
{ "acknowledged" : true, "matchedCount" : 0, "modifiedCount" : 0 }
> db.orders.findOne({"name":"misbah"});
null
> ^C
bye
[TE@fedora ~]$ mongo 10.10.12.248/te31455_db -u te31455 -p te31455
MongoDB shell version v4.4.4
connecting to: mongodb://10.10.12.248:27017/te31455_db?compressors=disabled&gssapiServiceName=mongodb
Implicit session: session { "id" : UUID("81396d24-53b6-4f17-a8cc-d3533752e146") }
MongoDB server version: 4.2.13
WARNING: shell and server versions do not match
---
The server generated these startup warnings when booting: 
2024-10-15T15:34:38.994+0530 I  STORAGE  [initandlisten] 
2024-10-15T15:34:38.994+0530 I  STORAGE  [initandlisten] ** WARNING: Using the XFS filesystem is strongly recommended with the WiredTiger storage engine
2024-10-15T15:34:38.994+0530 I  STORAGE  [initandlisten] **          See http://dochub.mongodb.org/core/prodnotes-filesystem
2024-10-15T15:34:43.427+0530 I  CONTROL  [initandlisten] 
2024-10-15T15:34:43.427+0530 I  CONTROL  [initandlisten] ** WARNING: Access control is not enabled for the database.
2024-10-15T15:34:43.427+0530 I  CONTROL  [initandlisten] **          Read and write access to data and configuration is unrestricted.
2024-10-15T15:34:43.427+0530 I  CONTROL  [initandlisten] 
---
> use te31455_db
switched to db te31455_db
> db.orders.findOne({"name":"misbah"});
null
> db.orders.find()
{ "_id" : ObjectId("67108d0ed07853b2bbea91ba"), "product" : "plant", "price" : 21, "customer" : "m" }
{ "_id" : ObjectId("67108d1bd07853b2bbea91bb"), "product" : "plant", "price" : 21, "customer" : "misbah" }
{ "_id" : ObjectId("67108d29d07853b2bbea91bc"), "product" : "plant", "price" : 21, "customer" : "misbah" }
{ "_id" : ObjectId("67108d29d07853b2bbea91bd"), "product" : "plant", "price" : 21, "customer" : "riya" }
{ "_id" : ObjectId("67108d29d07853b2bbea91be"), "product" : "brush", "price" : 150, "customer" : "anu" }
{ "_id" : ObjectId("67108d29d07853b2bbea91bf"), "product" : "brush", "price" : 150, "customer" : "anu" }
{ "_id" : ObjectId("67108d29d07853b2bbea91c0"), "product" : "book", "price" : 20, "customer" : "mansi" }
{ "_id" : ObjectId("67108d29d07853b2bbea91c1"), "product" : "book", "price" : 20, "customer" : "aryan" }
> db.orders.createIndex({ "customer": 1 });
{
	"createdCollectionAutomatically" : false,
	"numIndexesBefore" : 1,
	"numIndexesAfter" : 2,
	"ok" : 1
}
> db.orders.createIndex({ "product": 1, "price": 1 });
{
	"createdCollectionAutomatically" : false,
	"numIndexesBefore" : 2,
	"numIndexesAfter" : 3,
	"ok" : 1
}
> db.orders.getIndexes();
[
	{
		"v" : 2,
		"key" : {
			"_id" : 1
		},
		"name" : "_id_",
		"ns" : "te31455_db.orders"
	},
	{
		"v" : 2,
		"key" : {
			"customer" : 1
		},
		"name" : "customer_1",
		"ns" : "te31455_db.orders"
	},
	{
		"v" : 2,
		"key" : {
			"product" : 1,
			"price" : 1
		},
		"name" : "product_1_price_1",
		"ns" : "te31455_db.orders"
	}
]
> db.orders.insertMany([
...   {
...     "order_id": ObjectId(),
...     "product": "plant",
...     "price": 21,
...     "customer": "misbah"
...   },
...   {
...     "order_id": ObjectId(),
...     "product": "plant",
...     "price": 21,
...     "customer": "riya"
...   },
...   {
...     "order_id": ObjectId(),
...     "product": "brush",
...     "price": 150,
...     "customer": "anu"
...   },
...   {
...     "order_id": ObjectId(),
...     "product": "brush",
...     "price": 150,
...     "customer": "anu"
...   },
...   {
...     "order_id": ObjectId(),
...     "product": "book",
...     "price": 20,
...     "customer": "mansi"
...   },
...   {
...     "order_id": ObjectId(),
...     "product": "book",
...     "price": 20,
...     "customer": "aryan"
...   }
... ]);
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("67109680a978125ae3180ad1"),
		ObjectId("67109680a978125ae3180ad2"),
		ObjectId("67109680a978125ae3180ad3"),
		ObjectId("67109680a978125ae3180ad4"),
		ObjectId("67109680a978125ae3180ad5"),
		ObjectId("67109680a978125ae3180ad6")
	]
}
> use flowers
switched to db flowers
> db.flowers.insertMany([
...   {
...     "object_id": ObjectId(),
...     "name": "Rose",
...     "color": "Red",
...     "price": 100,
...   },
...   {
...     "object_id": ObjectId(),
...     "name": "Tulip",
...     "color": "Yellow",
...     "price": 120,
... 
...   }
... ]);
{
	"acknowledged" : true,
	"insertedIds" : [
		ObjectId("6710974aa978125ae3180ad9"),
		ObjectId("6710974aa978125ae3180ada")
	]
}
> db.flowers.createIndex({ "object_id": 1 }, { unique: true });
{
	"createdCollectionAutomatically" : false,
	"numIndexesBefore" : 1,
	"numIndexesAfter" : 2,
	"ok" : 1
}
> db.flowers.getIndexes();
[
	{
		"v" : 2,
		"key" : {
			"_id" : 1
		},
		"name" : "_id_",
		"ns" : "flowers.flowers"
	},
	{
		"v" : 2,
		"unique" : true,
		"key" : {
			"object_id" : 1
		},
		"name" : "object_id_1",
		"ns" : "flowers.flowers"
	}
]
> db.orders.find();
> db.orders.find()
> use orders
switched to db orders
> db.orders.find()
> use flowers
switched to db flowers
> db.flowers.find()
{ "_id" : ObjectId("6710974aa978125ae3180ad9"), "object_id" : ObjectId("6710974aa978125ae3180ad7"), "name" : "Rose", "color" : "Red", "price" : 100 }
{ "_id" : ObjectId("6710974aa978125ae3180ada"), "object_id" : ObjectId("6710974aa978125ae3180ad8"), "name" : "Tulip", "color" : "Yellow", "price" : 120 }
> use orders
switched to db orders
> db.orders.find()
> show te31455_db
uncaught exception: Error: don't know how to show [te31455_db] :
shellHelper.show@src/mongo/shell/utils.js:1191:11
shellHelper@src/mongo/shell/utils.js:819:15
@(shellhelp2):1:1
> show collections;
> show collections;
> use te31455_db
switched to db te31455_db
> show collections
orders
temp
> db.order.find()
> db.orders.find()
{ "_id" : ObjectId("67108d0ed07853b2bbea91ba"), "product" : "plant", "price" : 21, "customer" : "m" }
{ "_id" : ObjectId("67108d1bd07853b2bbea91bb"), "product" : "plant", "price" : 21, "customer" : "misbah" }
{ "_id" : ObjectId("67108d29d07853b2bbea91bc"), "product" : "plant", "price" : 21, "customer" : "misbah" }
{ "_id" : ObjectId("67108d29d07853b2bbea91bd"), "product" : "plant", "price" : 21, "customer" : "riya" }
{ "_id" : ObjectId("67108d29d07853b2bbea91be"), "product" : "brush", "price" : 150, "customer" : "anu" }
{ "_id" : ObjectId("67108d29d07853b2bbea91bf"), "product" : "brush", "price" : 150, "customer" : "anu" }
{ "_id" : ObjectId("67108d29d07853b2bbea91c0"), "product" : "book", "price" : 20, "customer" : "mansi" }
{ "_id" : ObjectId("67108d29d07853b2bbea91c1"), "product" : "book", "price" : 20, "customer" : "aryan" }
{ "_id" : ObjectId("67109680a978125ae3180ad1"), "order_id" : ObjectId("67109680a978125ae3180acb"), "product" : "plant", "price" : 21, "customer" : "misbah" }
{ "_id" : ObjectId("67109680a978125ae3180ad2"), "order_id" : ObjectId("67109680a978125ae3180acc"), "product" : "plant", "price" : 21, "customer" : "riya" }
{ "_id" : ObjectId("67109680a978125ae3180ad3"), "order_id" : ObjectId("67109680a978125ae3180acd"), "product" : "brush", "price" : 150, "customer" : "anu" }
{ "_id" : ObjectId("67109680a978125ae3180ad4"), "order_id" : ObjectId("67109680a978125ae3180ace"), "product" : "brush", "price" : 150, "customer" : "anu" }
{ "_id" : ObjectId("67109680a978125ae3180ad5"), "order_id" : ObjectId("67109680a978125ae3180acf"), "product" : "book", "price" : 20, "customer" : "mansi" }
{ "_id" : ObjectId("67109680a978125ae3180ad6"), "order_id" : ObjectId("67109680a978125ae3180ad0"), "product" : "book", "price" : 20, "customer" : "aryan" }
> { "_id" : ObjectId("67109680a978125ae3180ad1"), "order_id" : ObjectId("67109680a978125ae3180acb"), "product" : "plant", "price" : 21, "customer" : "misbah" }
uncaught exception: SyntaxError: unexpected token: ':' :
@(shell):1:8
> { "_id" : ObjectId("67109680a978125ae3180ad2"), "order_id" : ObjectId("67109680a978125ae3180acc"), "product" : "plant", "price" : 21, "customer" : "riya" }
uncaught exception: SyntaxError: unexpected token: ':' :
@(shell):1:8
> { "_id" : ObjectId("67109680a978125ae3180ad3"), "order_id" : ObjectId("67109680a978125ae3180acd"), "product" : "brush", "price" : 150, "customer" : "anu" }
uncaught exception: SyntaxError: unexpected token: ':' :
@(shell):1:8
> { "_id" : ObjectId("67109680a978125ae3180ad4"), "order_id" : ObjectId("67109680a978125ae3180ace"), "product" : "brush", "price" : 150, "customer" : "anu" }
uncaught exception: SyntaxError: unexpected token: ':' :
@(shell):1:8
> { "_id" : ObjectId("67109680a978125ae3180ad5"), "order_id" : ObjectId("67109680a978125ae3180acf"), "product" : "book", "price" : 20, "customer" : "mansi" }
uncaught exception: SyntaxError: unexpected token: ':' :
@(shell):1:8
> { "_id" : ObjectId("67109680a978125ae3180ad6"), "order_id" : ObjectId("67109680a978125ae3180ad0"), "product" : "book", "price" : 20, "customer" : "aryan" }
uncaught exception: SyntaxError: unexpected token: ':' :
@(shell):1:8
> > 
... 




