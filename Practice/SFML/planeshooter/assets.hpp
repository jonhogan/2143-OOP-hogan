#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

/***************************************************************************
****************************************************************************
*                                                                          *
* AssetHolder                                                              *
*                                                                          *
* Description:                                                             *
*       Manages the assets of the game                                     *
*                                                                          *
* Private Methods:                                                         *
*       None                                                               *
*                                                                          *
* Protected Methods:                                                       *
*                                                                          *
*                                                                          *
* Public Methods:                                                          *
*                                                                          *
****************************************************************************
***************************************************************************/

const sf::Time FRAMETIME = sf::seconds(1.f/60.f);
//const sf::Texture& get (Texture::ID id) const;

namespace assets
{
    enum ID {background, spaceship};
}

class AssetsHolder
{
    protected:
        std::map<assets::ID, std::unique_ptr<sf::Texture>> m_assetMap;

    public:
        void AssetsHolder::load(assets::ID id, const std::string& filename)
        {
            std::unique_ptr<sf::Texture> asset(new sf::Texture());
            asset -> loadFromFile(filename);

            m_assetMap.insert(std::make_pair(id,std::move(asset)));
        }

};