# Love has no limits

The goal of this project is to create a teddy to your partner, or any people you love !!

## How I think it
- Firstly, pair teddies
- Press a button to light on the paired teddy

Globally, that's what I see :
```mermaid
flowchart LR
    subgraph Teddy_1
        conf_1["Config unit"]
        com_1["Communication unit"]
        ihm_1["HMI unit"]

    end

    subgraph Teddy_2
        conf_2["Config unit"]
        com_2["Communication unit"]
        ihm_2["HMI unit"]

    end

    me <--> ihm_1
    me --> conf_1
    my_super_genial_girlfriend <--> ihm_2
    my_super_genial_girlfriend --> conf_2

    com_1 <-->|"Communication channel"| com_2
```

## How I implement it
I will create different configurations, and choose one of them.

### Config unit
- By USB formatted filesystem 
- By USB as serial channel
- By serial
- By web interface
- By bluetooth
