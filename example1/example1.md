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
{% include_relativehello.c %}
```

## main.c
```c
{% include_relative main.c %}
```

