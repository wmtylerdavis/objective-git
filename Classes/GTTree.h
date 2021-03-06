//
//  GTTree.h
//  ObjectiveGitFramework
//
//  Created by Timothy Clem on 2/22/11.
//
//  The MIT License
//
//  Copyright (c) 2011 Tim Clem
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//


#import "GTObject.h"

@class GTTreeEntry;
@class GTIndex;

@interface GTTree : GTObject

// The underlying libgit2 tree.
@property (nonatomic, readonly) git_tree *git_tree;

// The number of entries in the tree.
@property (nonatomic, readonly) NSUInteger entryCount;

// Get a entry at the specified index
//
// index - index to retreive entry from
//
// returns a GTTreeEntry or nil if there is nothing at the index
- (GTTreeEntry *)entryAtIndex:(NSUInteger)index;

// Get a entry by name
//
// name - the name of the entry
//
// returns a GTTreeEntry or nil if there is nothing with the specified name
- (GTTreeEntry *)entryWithName:(NSString *)name;

// Merges the given tree into the receiver in memory and produces the result as
// an index.
//
// otherTree    - The tree with which the receiver should be merged. Cannot be
//                nil.
// ancestorTree - The common ancestor of the two trees, or nil if none.
// error        - The error if one occurred.
//
// Returns an index which represents the result of the merge, or nil if an error
// occurred.
- (GTIndex *)merge:(GTTree *)otherTree ancestor:(GTTree *)ancestorTree error:(NSError **)error;

@end
