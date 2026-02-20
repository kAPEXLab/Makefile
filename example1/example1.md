---
layout: default
title: example1
parent: Examples
nav_order: 1
---


# example1

## Files in `example1/`
{% include listdir.html dir='/example1/' %}
---

## README (example-level)
{% capture md %}{% include_relative example1/readme.md %}{% endcapture %}
{{ md | markdownify }}

## Makefile
```make
{% include_relative example1/Makefile %}
```

## hello.h
```c
{% include_relative example1/hello.h %}
```

## hello.c
```c
{% include_relative example1/hello.c %}
```

## main.c
```c
{% include_relative example1/main.c %}
```

