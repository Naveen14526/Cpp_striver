import React from 'react';
import ReactDOM from 'react-dom/client';
import './styles.css';

function App() {
  const [featured, setFeatured] = React.useState(null);
  const [playlists, setPlaylists] = React.useState([]);
  const [library, setLibrary] = React.useState([]);
  const [trending, setTrending] = React.useState([]);
  const [query, setQuery] = React.useState('');
  const [searchResults, setSearchResults] = React.useState([]);
  const [error, setError] = React.useState('');

  React.useEffect(() => {
    const loadDashboard = async () => {
      try {
        const [featuredRes, playlistsRes, libraryRes, trendingRes] = await Promise.all([
          fetch('/api/featured'),
          fetch('/api/playlists'),
          fetch('/api/library'),
          fetch('/api/trending')
        ]);

        if (!featuredRes.ok || !playlistsRes.ok || !libraryRes.ok || !trendingRes.ok) {
          throw new Error('Unable to load the music dashboard.');
        }

        const featuredData = await featuredRes.json();
        const playlistsData = await playlistsRes.json();
        const libraryData = await libraryRes.json();
        const trendingData = await trendingRes.json();

        setFeatured(featuredData);
        setPlaylists(playlistsData);
        setLibrary(libraryData);
        setTrending(trendingData);
      } catch (loadError) {
        setError(loadError.message || 'Something went wrong while loading the dashboard.');
      }
    };

    loadDashboard();
  }, []);

  React.useEffect(() => {
    const timer = setTimeout(async () => {
      if (!query.trim()) {
        setSearchResults([]);
        return;
      }

      try {
        const response = await fetch(`/api/search?q=${encodeURIComponent(query)}`);
        const data = await response.json();
        setSearchResults(data.results || []);
      } catch (searchError) {
        setSearchResults([]);
      }
    }, 250);

    return () => clearTimeout(timer);
  }, [query]);

  if (error) {
    return (
      <div className="error-state">
        <h2>Unable to load Pulse</h2>
        <p>{error}</p>
      </div>
    );
  }

  if (!featured) {
    return <div className="loading-state">Loading your soundtrack...</div>;
  }

  return (
    <div className="spotify-shell">
      <aside className="sidebar">
        <div className="brand-mark">P</div>
        <nav className="nav">
          <button className="nav-item active">Home</button>
          <button className="nav-item">Search</button>
          <button className="nav-item">Your Library</button>
        </nav>

        <div className="sidebar-block">
          <p className="section-label">Playlists</p>
          {playlists.slice(0, 3).map((playlist) => (
            <div className="mini-link" key={playlist.id}>
              <span className="dot" style={{ background: playlist.color }} />
              {playlist.title}
            </div>
          ))}
        </div>
      </aside>

      <main className="main-panel">
        <header className="topbar">
          <div className="search-wrap">
            <span className="search-icon">⌕</span>
            <input
              type="text"
              value={query}
              onChange={(event) => setQuery(event.target.value)}
              placeholder="Search songs, artists, or genres"
            />
          </div>

          <div className="profile-pill">
            <div className="avatar">N</div>
            <span>Neve</span>
          </div>
        </header>

        {query && searchResults.length > 0 && (
          <div className="search-panel">
            {searchResults.map((result) => (
              <div key={result.id} className="search-item">
                <span className="search-tag">{result.genre}</span>
                <span>{result.title}</span>
                <small>{result.artist}</small>
              </div>
            ))}
          </div>
        )}

        <section className="hero-card" style={{ background: featured.accent }}>
          <div className="hero-copy">
            <p className="eyebrow">Featured mix</p>
            <h1>{featured.title}</h1>
            <p>{featured.description}</p>
            <div className="hero-meta">
              <span>{featured.artist}</span>
              <span>{featured.listeners}</span>
              <span>{featured.duration}</span>
            </div>
          </div>
          <div className="hero-visual">
            <div className="album-orb" />
          </div>
        </section>

        <section className="content-section">
          <div className="section-header">
            <h2>Made for you</h2>
            <button className="text-button">Show all</button>
          </div>

          <div className="playlist-grid">
            {playlists.map((playlist) => (
              <article key={playlist.id} className="playlist-card">
                <div className="cover-art" style={{ background: playlist.color }} />
                <h3>{playlist.title}</h3>
                <p>{playlist.owner}</p>
              </article>
            ))}
          </div>
        </section>

        <section className="content-section two-column">
          <div className="panel-box">
            <div className="section-header">
              <h2>Your library</h2>
              <button className="text-button">View more</button>
            </div>

            <div className="library-grid">
              {library.map((item) => (
                <div key={item.id} className="library-item">
                  <div className="library-cover" style={{ background: item.color }} />
                  <div>
                    <strong>{item.title}</strong>
                    <small>{item.subtitle}</small>
                  </div>
                </div>
              ))}
            </div>
          </div>

          <div className="panel-box">
            <div className="section-header">
              <h2>Trending now</h2>
              <button className="text-button">Play</button>
            </div>

            <ul className="track-list">
              {trending.map((track) => (
                <li key={track.id} className="track-row">
                  <div className="track-thumb" style={{ background: track.color }} />
                  <div className="track-copy">
                    <strong>{track.title}</strong>
                    <span>{track.artist}</span>
                  </div>
                  <span className="track-genre">{track.genre}</span>
                  <span className="track-duration">{track.duration}</span>
                </li>
              ))}
            </ul>
          </div>
        </section>
      </main>
    </div>
  );
}

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);
