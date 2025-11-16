#ifndef STATE_H_
#define STATE_H_

class State
{
private:
public:
    virtual void Update() = 0;
    virtual void Render() = 0;

    virtual ~State() = default;
};

class GameState : public State
{
private:
public:
    GameState();
    ~GameState();

    void Update() override;
    void Render() override;
};

class MenuState : public State
{
private:
public:
    MenuState();
    ~MenuState();

    void Update() override;
    void Render() override;
};

#endif
