---
layout: default
title: Example1 Building and Running myapp Using Makefile
nav_order: 2
---


# Example1 Building and Running myapp Using Makefile

## Files in `example1/`
{% include listdir.html dir='/example1/' %}
---

## README (example-level)
{% capture md %}{% include_relative readme.md %}{% endcapture %}
{{ md | markdownify }}

## Makefile
```make
{% include_relative Makefile %}
```

## hello.h
```c
{% include_relative hello.h %}
```

## hello.c
```c
{% include_relative hello.c %}
```

## main.c
```c
{% include_relative main.c %}
```

