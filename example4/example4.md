---
layout: default
title: example4
parent: Examples
nav_order: 4
---

# example4

## Files in `example4/`
{% include listdir.html dir='/example4/' %}

---

## README (example-level)
{% capture md %}{% include_relative readme.md %}{% endcapture %}
{{ md | markdownify }}

## Makefile
```make
{% include_relative Makefile %}
```

## add.h
```c
{% include_relative add.h %}
```

## add.c
```c
{% include_relative add.c %}
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

