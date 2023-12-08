# Project Overview: Get_Next_Line_42

This project involves the development of a function designed to retrieve a line from a file descriptor.

For a comprehensive guide on the concept, I recommend consulting [@Raspurrin's 42Guides](https://github.com/Raspurrin/42Guides/blob/main/get_next_line/get_next_line.md), which provides valuable insights.

## Implementation Approach

I adopted a unique implementation approach using an Intrusive Linked List. While this methodology is not obligatory, it proved instrumental in expanding my understanding of linked list implementations. The decision was not driven by showcasing prowess but rather stemmed from overcoming challenges faced in a prior implementation, where timeouts were prevalent.

## Visual Representation of the Concept

![Concept Visual](https://user-images.githubusercontent.com/66947064/183244165-8375f657-5c85-4c64-98e2-47e206932e70.png)

## Intrusive Linked List

![Intrusive Linked List](https://user-images.githubusercontent.com/66947064/183244206-088c95b7-cccd-4488-ac0b-54adceb879b1.png)

## Advantages of Array Approach

![Array Approach Advantages](https://user-images.githubusercontent.com/66947064/183244646-b5e47b3f-01c0-4cea-9ad6-37642b9e6f7f.png)

For a more detailed understanding, refer to [Data Structure the lord](https://www.data-structures-in-practice.com/intrusive-linked-lists/).

## Performance Considerations

I propose that this implementation is potentially faster, although a benchmark test is warranted. I invite anyone knowledgeable in this area to conduct such tests and share the findings.

## Resources and Tools Used

- **Debugging:** Utilized tools such as lldb or gdb. A valuable resource for debugging techniques can be found at [Debug Me !!](https://sebastienwae.github.io/debugging-42/).

- **Memory Allocation Intuition:** Continued learning and reference from [Stack Overflow](https://stackoverflow.com/questions/1538420/difference-between-malloc-and-calloc).

- **Static Variables and Memory Allocation:** Acknowledged the potential pitfalls of allocating large memory in the stack with static variables, especially in the context of avoiding timeouts.

Finally, a crucial aspect of my learning process involved deriving insights from evaluations. Continuous improvement is paramount in refining programming skills.
